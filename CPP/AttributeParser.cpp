//
//  AttributeParser.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 24/09/2016.
//
//  https://www.hackerrank.com/challenges/attribute-parser

#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <regex>

using namespace std;

/**
 Explode a string using delimeter passed as parameter.
 
 @param s string to be exploded.
 @param delim delimiter to be used during explode process.
 
 @returns vector with substring after "explosion".
 */
vector<string> explode(const string &s, char delim) {
    
    vector<string> elems;
    stringstream ss(s);
    string item;
    
    while (getline(ss, item, delim)) {
        
        elems.push_back(item);
    }
    
    return elems;
}

/**
 Trim a string.
 
 @param string to be trimmed.
 
 @returns a copy of the string trimmed.
 */
string trim(string& str) {
    
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    
    return str.substr(first, (last - first + 1));
}

/**
 Struct used to represend tags of the hrml document.
 */
struct Tag {
    
    //Tag name.
    string name;
    //Father of the tag.
    Tag* father;
    //Children tags of the tag.
    vector<Tag*> children;
    //Attributes of the tag.
    map<string, string> attributes;
};

/**
 Visit the children of the tag received as input and
 search for a specific tag with a given name.
 
 @param tag the tag to be found.
 @param tagNameToBeFound the tag to be found.
 
 @returns the children tag found if there's one with the given name, or null.
 */
Tag* visitChildren(Tag* tag, string tagNameToBeFound) {
    
    for (Tag* currentChildren : tag->children) {
        
        if (currentChildren->name == tagNameToBeFound) {
            
            return currentChildren;
        }
    }
    
    return nullptr;
}

/**
 Find root tag given a tag name.
 
 @param rootTags vector of root tags.
 @param tagNameToBeFound tag to be found in the vector of root nodes.
 
 @returns the root tag found, if there's one.
 */
Tag* findRootTag(const vector<Tag*>& rootTags, const string& tagNameToBeFound) {
    
    for (int i = 0; i < rootTags.size(); i++) {
        
        if (rootTags[i]->name == tagNameToBeFound) {
            
            return rootTags[i];
        }
    }
    
    return nullptr;
}

/**
 Find a tag.
 
 @param tagPositionInQuery tag position in query.
 @param tagToBeFound tag to be found (ASSIGNED new tag found).
 @param rootTags vector of root tags.
 @param tagNameToBeFound tag to be found in the vector of root nodes.
 */
void findTag(int tagPositionInQuery, Tag*& tagToBeFound, const vector<Tag*>& rootTags, const string& tagNameToBeFound) {
    
    if (tagPositionInQuery == 0) {
        
        tagToBeFound = findRootTag(rootTags, tagNameToBeFound);
    } else {
        
        tagToBeFound = visitChildren(tagToBeFound, tagNameToBeFound);
    }
}

int main() {
    
    //n is the number of lines.
    //q is the number of queries.
    int n, q;
    
    cin >> n >> q;
    
    //Read parameters.
    string currentLine;
    getline(cin, currentLine);
    
    regex openTag(R"(<([a-z0-9]+))");
    regex attributes(R"(([^\s]+){1}(\s)?(=){1}(\s)?(".*?"){1})");
    
    Tag* currentFatherTag = nullptr;
    Tag* lastCreatedTag = nullptr;
    vector<Tag*> rootTags;
    
    for (int i = 0; i < n; i++) {
        
        //Get current hrml line.
        getline(cin, currentLine);
        
        smatch m;
        bool foundOpeningTag = regex_search(currentLine, m, openTag);
        
        if (foundOpeningTag) {
            
            Tag* newTag = new Tag();
            newTag->name = m.str(1);
            
            if (currentFatherTag != nullptr) {
                
                //Add new tag to children of current father tag.
                currentFatherTag->children.push_back(newTag);
                newTag->father = currentFatherTag;
            }
            
            currentFatherTag = newTag;
            
            //Extract attributes from current tag.
            regex_iterator<string::iterator> rit(currentLine.begin(), currentLine.end(), attributes);
            regex_iterator<string::iterator> rend;
            
            while (rit != rend) {
                
                vector<string> explodedAttribute = explode(rit->str(), '=');
                string key = explodedAttribute[0];
                string value = explodedAttribute[1];
                
                key = trim(key);
                value = trim(value);
                
                value.erase(remove(value.begin(), value.end(), '\\'), value.end());
                value.erase(remove(value.begin(), value.end(), '"'), value.end());
                
                newTag->attributes.insert(make_pair(key, value));
                
                rit++;
            }
            
            //Last open tag is the last created tag.
            lastCreatedTag = newTag;
        } else {
            
            //Closing tag.
            //Warning: multiple root tags in a some test cases.
            if (lastCreatedTag && lastCreatedTag->father) {
                
                //Go back to previous tag.
                //In this case currentFatherTag is not a root tag.
                currentFatherTag = lastCreatedTag->father;
                lastCreatedTag = lastCreatedTag->father;
            } else {
                
                if (currentFatherTag) {
                    
                    //In this case currentFatherTag is a root tag.
                    rootTags.push_back(currentFatherTag);
                    currentFatherTag = nullptr;
                }
            }
        }
    }
    
    string query;
    Tag* tagToBeFound;
    
    for (int i = 0; i < q; i++) {
        
        cin >> query;
        
        tagToBeFound = nullptr;
        vector<string> queryExploded = explode(query, '.');
        
        for (int h = 0; h < queryExploded.size(); h++) {
            
            vector<string> query = explode(queryExploded[h], '~');
            
            if (query.size() > 1) {
                
                string lastTag = query[0];
                string attribute = query[1];
                
                findTag(h, tagToBeFound, rootTags, lastTag);
                
                //Tag or attribute not found.
                if (tagToBeFound == nullptr ||
                    tagToBeFound->attributes.find(attribute) == tagToBeFound->attributes.end()) {
                    
                    cout << "Not Found!" << endl;
                } else {
                    
                    cout << tagToBeFound->attributes[attribute] << endl;
                }
            } else {
                
                //Find generic tag
                findTag(h, tagToBeFound, rootTags, queryExploded[h]);
                
                if (tagToBeFound == nullptr) {
                    
                    cout << "Not Found!" << endl;
                    break;
                }
            }
        }
    }
    
    return 0;
}
