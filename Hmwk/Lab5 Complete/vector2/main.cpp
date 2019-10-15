/* 
 * File:   main.cpp
 * Author: Student Byoung Mo Lee
 * Purpose: learning vector stl(p279)
 * Created on October 9, 2019, 10:10 PM
 */

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    vector<string> sentence;

    sentence.reserve(5);

    sentence.push_back("Hello,");
    sentence.insert(sentence.end(),{"how","are","you","?"});

    copy (sentence.cbegin(), sentence.cend(),
          ostream_iterator<string>(cout," "));
    cout << endl;

    cout << "  max_size(): " << sentence.max_size() << endl;
    cout << "  size():     " << sentence.size()     << endl;
    cout << "  capacity(): " << sentence.capacity() << endl;

    swap (sentence[1], sentence[3]);

    sentence.insert (find(sentence.begin(),sentence.end(),"?"),
                     "always");

    sentence.back() = "!";
    
    copy (sentence.cbegin(), sentence.cend(),
          ostream_iterator<string>(cout," "));
    cout << endl;

    cout << "  size():     " << sentence.size()     << endl;
    cout << "  capacity(): " << sentence.capacity() << endl;

    sentence.pop_back();
    sentence.pop_back();
    sentence.shrink_to_fit();

    cout << "  size():     " << sentence.size()     << endl;
    cout << "  capacity(): " << sentence.capacity() << endl;
}