#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include "Speaker.hpp"
#include <algorithm>
#include <numeric>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;
typedef pair<int, Speaker> PAIR;
#define FILENAME "speech.csv"
class SpeechManager
{
public:
    SpeechManager();
    ~SpeechManager();
    void Showmenu();
    void exitSystem();
    void initSystem();
    void createSpeaker();
    void startSpeech();
    void speechDraw();
    void speechConstest();
    double geneScore();
    void renew();
    void showScore();
    void getPwd();
    class compare
    {
    public:
        bool operator()(const PAIR &p1, const PAIR &p2);
    };
    void saveRecord(ofstream &ofs);
    void loadRecord();
    void clearRecord();
    vector<int> v1;
    vector<int> v2;
    vector<int> sVictory;
    map<int, Speaker> m_Speaker;
    int m_Turn;
    bool Is_empty;
};
ostream &operator<<(ostream &cout, Speaker &sp);