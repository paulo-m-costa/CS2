//
//  align.cpp
//  dna_alignment
//
//  Created by Erika DeBenedictis on 1/27/13.
//  Copyright (c) 2014 California Institute of Technology. All rights reserved.
//
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// scoring values
#define GAP_SCORE -5
#define MISMATCH -1
#define MATCHING 2

/**
 * @brief Packages the score and instruction string the align function returns
 */
struct align_result {
    int score;      // score of this alignment
    string inst;    // instruction on how to align the inputs

    align_result(int s, string i) {
        this->score = s;
        this->inst = i;
    }
    align_result() {
        this->score = 0;
        this->inst = "";
    }
};

// memo_type will allow us to hash the string input to align
// with its output for memoization
typedef unordered_map<string, align_result> memo_type;

/**
 * @brief Function takes two strings, s and t, and produces an align_result
 * of the highest alignment score and its corresponding instruction str.
 */

int maximum(int i_1, int i_2, int i_3)
{
    if (i_1 >= i_2 && i_1 >= i_3)
    {
        return i_1;
    }
    else if (i_2 >= i_1 && i_2 >= i_3)
    {
        return i_2;
    }
    return i_3;
}

align_result align(string s, string t, memo_type &memo) {
    // if this result is memoized, use recorded result
    string key = s + "," + t;
    if (memo.count(key) > 0){
      return memo[key];
    }

    string s_;
    string t_;
    int sc_1, sc_2, sc_3, max;
    string inst_1, inst_2, inst_3;
    align_result answer;

    if (s.length() == 0)
    {
        /*
         * Base case - s is empty.
         */
        answer.score = (int) t.length() * -5;
        string inst = string((int) t.length(), 't');
        answer.inst = inst;
        return answer;
    }
    else if (t.length() == 0)
    {
        /*
         * Base case - t is empty.
         */
        answer.score = (int) s.length() * -5;
        string inst = string((int) s.length(), 's');
        answer.inst = inst;
        return answer;
    }
    else
    {
        // Gap in s
        s_ = s;
        t_ = t.substr(1, -1);
        /*
         * Adds the scores and inst strings for the removed characters
         * as well as the rest of the string.
         */
        sc_1 = align("", t.substr(0, 1), memo).score
            + align(s_, t_, memo).score;
        inst_1 = align("", t.substr(0, 1), memo).inst
            + align(s_, t_, memo).inst;

        // Gap in t
        s_ = s.substr(1, -1);
        t_ = t;
        
        sc_2 = align(s.substr(0, 1), "", memo).score
            + align(s_, t_, memo).score;
        inst_2 = align(s.substr(0, 1), "", memo).inst
            + align(s_, t_, memo).inst;

        // No gap
        s_ = s.substr(1, -1);
        t_ = t.substr(1, -1);
        
	// Calculates score for the removed characters
        if (s.substr(0, 1).compare(t.substr(0, 1)) == 0)
        {
            sc_3 = 2;
            inst_3 = "|";
        }
        else
        {
            sc_3 = -1;
            inst_3 = "*";
        }
        // Adds the score for the rest of the string
        sc_3 += align(s_, t_, memo).score;
        inst_3 += align(s_, t_, memo).inst;

        // Get the highest score to choose the right inst string
        max = maximum(sc_1, sc_2, sc_3);
        if (max == sc_1)
        {
            answer.score = max;
            answer.inst = inst_1;
        }
        else if (max == sc_2)
        {
            answer.score = max;
            answer.inst = inst_2;
        }
        else if (max == sc_3)
        {
            answer.score = max;
            answer.inst = inst_3;
        }
    }
    /* Before you return your calculated  align_result object,
       memoize it like so:*/

    memo[key] = answer;
    return answer;
}

/**
 * @brief Wrapper function to print the results of align
 */
void DNA_align(string s, string t) {
    cout << endl << "Calling DNA align on strings " << s << ", " << t << endl;

    // create the memoization system
    memo_type memo;

    align_result answer = align(s, t, memo);
    string ans = answer.inst;

    // Printing section
    // line where string s will be printed, spaces inserted
    string line1 = "";
    // line where string t will be printed, spaces inserted
    string line2 = "";
    // description of the relationship between s and t here (* | s t)
    string line3 = "";

    int j = 0;      // running index in s
    int k = 0;      // running index in t

    for (unsigned int m = 0; m < ans.length(); m++) {
        // i is the next element in our instruction string ans
        string i = ans.substr(m, 1);

        // only in s
        if(i.compare("s") == 0){
            line1 += s[j]; j++;
            line2 += " ";
            line3 += "s";
        }

        // only in t
        else if (i.compare("t") == 0){
            line1 += " ";
            line2 += t[k]; k++;
            line3 += "t";
        }

        // mismatch
        else if (i.compare("*") == 0){
            line1 += s[j]; j++;
            line2 += t[k]; k++;
            line3 += "*";
        }

        // match
        else {
            line1 += s[j]; j++;
            line2 += t[k]; k++;
            line3 += "|";
        }
    }
    cout << line1 << endl << line2 << endl << line3 << endl;
    printf("Highest Score: %d\n", answer.score);
}

int main(){
    // some test cases to begin with
    DNA_align("",   "a");
    DNA_align("bbbb",  "");
    DNA_align("a", "a");
    DNA_align("b",  "a");
    DNA_align("b",  "ba");
    DNA_align("ab", "ba");
    DNA_align("ab", "b");
    DNA_align("ACTGGCCGT", "TGACGTAA");
    DNA_align("abracadabra", "avada kedavra");
    DNA_align("AGACCTGA", "TAGAGCCTGA ");
    DNA_align("GAAAAAAAAAAAAAAA", " GAAAA AAAAA AAAA");
    return 0;
}