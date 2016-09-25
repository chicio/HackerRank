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

struct Tag {
    
    string name;
    Tag* father;
    vector<Tag*> children;
    map<string, string> attributes;
};

vector<string> explode(const string &s, char delim) {
    
    vector<string> elems;
    stringstream ss(s);
    string item;
    
    while (getline(ss, item, delim)) {
        
        elems.push_back(item);
    }
    
    return elems;
}

string trim(string& str) {
    
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    
    return str.substr(first, (last - first + 1));
}

static Tag* tagFound;

void visitChildren(Tag* tag, string tagToBeFound) {
    
    for (Tag* currentChildren : tag->children) {
        
        if (currentChildren->name == tagToBeFound) {
            
            tagFound = currentChildren;
            return;
        }
    }
}

int main() {
    
    //n is the number of lines.
    //q is the number of queries.
    int n, q;
    
    cin >> n >> q;
    
    //Read parameters.
    vector<string> queries(q);
    string hrmlSource = "";
    string currentLine;
    getline(cin, currentLine);
    
    regex openTag(R"(<([a-z0-9]+))");
    regex attributes(R"(([^\s]+){1}(\s)?(=){1}(\s)?(".*?"){1})");
    
    Tag* currentFatherTag = nullptr;
    Tag* rootTag = nullptr;
    
    for (int i = 0; i < n; i++) {
        
        getline(cin, currentLine);
        
        smatch m;
        bool foundOpeningTag = regex_search(currentLine, m, openTag);
        
        if (foundOpeningTag) {
            
            Tag* newTag = new Tag();
            newTag->name = m.str(1);
            
            if(rootTag == nullptr) {
                
                //Set root tag of document.
                rootTag = newTag;
            }
            
            if (currentFatherTag != nullptr) {
                
                currentFatherTag->children.push_back(newTag);
                newTag->father = currentFatherTag;
            } else {
                
                currentFatherTag = newTag;
            }
            
            currentFatherTag = newTag;
            
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
        } else {
            
            //closing tag.
            if(currentFatherTag->father) {
                
                currentFatherTag = currentFatherTag->father;
            }
        }
    }
    
    string query;
    Tag* tagToBeFound = rootTag;
    
    for (int i = 0; i < q; i++) {
        
        cin >> query;
        
        vector<string> queryExploded = explode(query, '.');
        
        for (int h = 0; h < queryExploded.size(); h++) {
            
            size_t found = queryExploded[h].find("~");
            
            if (found != string::npos) {
                
                vector<string> lastQuery = explode(queryExploded[h], '~');
                string lastTag = lastQuery[0];
                string attribute = lastQuery[1];
                
                if (h == 0 && rootTag->name != lastTag) {
                    
                    cout << "Not Found!" << endl;
                    break;
                }
                
                tagFound = nullptr;
                visitChildren(tagToBeFound, lastTag);

                if (h == 0 && rootTag->name == lastTag) {
                    
                    tagFound = rootTag;
                }
                
                if (tagFound != nullptr) {
                    
                    //Key exists
                    if (tagFound->attributes.find(attribute) == tagFound->attributes.end()) {
                        
                        cout << "Not Found!" << endl;
                        break;
                    } else {
                        
                        cout << tagFound->attributes[attribute] << endl;
                    }
                } else {
                    
                    cout << "Not Found!" << endl;
                    break;
                }
            } else {
                
                if (h == 0) {
                    
                    if (rootTag->name == queryExploded[h]) {
                        
                        tagToBeFound = rootTag;
                    } else {
                        
                        cout << "Not Found!" << endl;
                        break;
                    }
                } else {
                    
                    tagFound = nullptr;
                    visitChildren(tagToBeFound, queryExploded[h]);
                    
                    if (tagFound != nullptr) {
                        
                        tagToBeFound = tagFound;
                    } else {
                        
                        cout << "Not Found!" << endl;
                        break;
                    }
                }
            }
        }
    }
    
    return 0;
}

//Not working (multiple root node).
//https://hr-testcases-us-east-1.s3.amazonaws.com/15604/input04.txt?AWSAccessKeyId=AKIAJAMR4KJHHUS76CYQ&Expires=1474841404&Signature=RXJfi9S%2FULVSW4pEJOb6aOvh70M%3D&response-content-type=text%2Fplain
//https://hr-testcases-us-east-1.s3.amazonaws.com/15604/output04.txt?AWSAccessKeyId=AKIAJAMR4KJHHUS76CYQ&Expires=1474841405&Signature=CS46gPJWmPkXByyZS8u5wtvIpLI%3D&response-content-type=text%2Fplain

