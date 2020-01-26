//
//  main.cpp
//  sts
//
//  Created by 이한범 on 26/01/2020.
//  Copyright © 2020 Hanbum.Lee. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <string>

using namespace std;

#define themeDBPath "../db/themes.txt"
#define platformDBPath "../db/platforms.txt"
#define languageDBPath "../db/languages.txt"

const vector<string> paths = {themeDBPath, platformDBPath, languageDBPath};

enum DBTypes
{
    Theme = 0,
    Platform = 1,
    language = 2
};

string SelectRandomItem(vector<string>& db)
{
    srand((unsigned int)time(0));
    return db[rand() % (db.size())];
}

string GetItemFromDB(int type, vector<string>& db)
{
    ifstream fs;
    fs.open(paths[type]);
    
    string buffer;
    
    while (fs.peek() != EOF)
    {
        getline(fs, buffer);
        db.push_back(buffer);
    }
    
    fs.close();
    
    return SelectRandomItem(db);
}

void AddToDB(int type)
{
    string item;
    std::getline(std::cin, item);
    
    ofstream fs;
    fs.open(paths[type], ios::app);
    fs << item << endl;
    fs.close();
}

void ShowDB(int type)
{
    ifstream fs;
    fs.open(paths[type]);
    
    string buffer;
    
    while (fs.peek() != EOF)
    {
        getline(fs, buffer);
        cout << buffer << endl;
    }
    
    fs.close();
}

void PickDB()
{
    vector<string> db;
    
    for (int i = 0; i < paths.size(); i++)
    {
        cout << GetItemFromDB(i, db);
        
        if (i < 2) cout << "//";
        else cout << endl;
        
        db.clear();
    }
}

void ShowDBMenu(bool isShow)
{
    cout << "⎡⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎤" << endl;
    cout << "⎜ 1. Theme       |" << endl;;
    cout << "⎜ 2. Platform    |" << endl;;
    cout << "⎜ 3. Language    |" << endl;;
    cout << "⎜ 4. Back        |" << endl;;
    cout << "⎣⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎦" << endl;;
    
    int select;
    cin >> select;
    cin.ignore();
    
    if (select == 4)
        return;
    
    if (isShow)
    {
        ShowDB(select - 1);
    }
    else
    {
        AddToDB(select - 1);
    }
    
    return;
}

void ShowDefaultMenu()
{
    cout << "⎡⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎤" << endl;
    cout << "⎜ 1. Add         |" << endl;;
    cout << "⎜ 2. Show        |" << endl;;
    cout << "⎜ 3. Pick        |" << endl;;
    cout << "⎜ 4. End         |" << endl;;
    cout << "⎣⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎦" << endl;;
    
    int select;
    cin >> select;
    cin.ignore();
    
    switch (select)
    {
        case 1:
            ShowDBMenu(false);
            break;
        case 2:
            ShowDBMenu(true);
            break;
        case 3:
            PickDB();
            return;
        default:
            return;
    }

    ShowDefaultMenu();
}

int main(int argc, const char * argv[])
{
    ShowDefaultMenu();
    
    return 0;
}
