#include <iostream>
#include <algorithm>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

/*
* To split a string into a set of string for given 
* delemeter character(s) 
*/
vector<string> split(string str)
{
    vector<string> result;
    char buf[200];
    size_t length = str.copy(buf,str.length(),0);
    buf[length] = '\0';
    char *p = strtok(buf, " \t");
	while (p) {
		string temp = p;
		result.push_back(temp);
	   /* printf ("Token: %s\n", p);*/
	    p = strtok(NULL, " \t");
	}

    return result;
}

/*
* To print current sentential form
*/
void print_sentence(vector<string> sentence,ostream &out){
	int size = sentence.size();
	for (int i = 0; i < size; ++i)
	{
		out << sentence[i] << " " ;
	}
	out << endl;
}

int main(int argc, char const *argv[])
{
	ifstream in("production.txt");			// File containing productions
	ofstream out("sententialForm.txt");		// File will have sentential forms
	if (!in)
	{
		cout << "Error in opening file containing productions." << endl;
		return 0;
	}
	if (!out)
	{
		cout << "Error in opening file to write sentential forms." << endl;
		return 0;
	}


	vector<string> sentence;
	string line;
	int i = 0;
	while(getline(in, line)){
		vector<string> temp_sentence =  split(line);
		if (temp_sentence.size() == 0)
		{
			continue;	
		}
		if (i == 0)
		{
			//cout << "First Time" << endl;
			int size = temp_sentence.size();
			for (int j = 1; j < size; ++j)
			{
				sentence.push_back(temp_sentence[j]);
			}
			//print_sentence(sentence);
		}
		else{
			string nont = temp_sentence[0];
			vector<string>::iterator nont_i = std::find(sentence.begin(),sentence.end(),nont);
			if (nont_i != sentence.end())
			{
				//cout << "Found The Match" << endl;
				int nont_pos = nont_i - sentence.begin();
				sentence.erase(sentence.begin() + nont_pos);
				
				int size_temp_sentence = temp_sentence.size();
				//cout << size_temp_sentence << endl;
				for (int j = size_temp_sentence-1; j>0 ; --j)
				{
					sentence.insert(sentence.begin() + nont_pos, temp_sentence[j]);
				}
				//print_sentence(sentence);
			}
			//cout << "No Match Found" << endl;
			//print_sentence(sentence);



		}
		i++;
		out<< endl<<"Sentential Form After " << i << "th Production" << endl;
		print_sentence(sentence,out);
		
	}
	return 0;
}
