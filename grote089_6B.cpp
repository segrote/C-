//Sever Grote
//CSci 1113 HW 06B

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

bool isVowel(char vowelOrNah);
char capitalize(char txt);
char lowercase(char txt);
string quasiLatinGenerator(string word, bool firstWord);
string twoConsonants(string word, bool firstWord);
string consonantVowel(string word, bool firstWord);
string startsWithVowel(string word, bool firstWord);

int main()
{
  string txt, word;
  int i, endOfWord;
  ifstream fin;
  ofstream fout;
  bool firstWord;

  fin.open("input.txt");
  fout.open("output.txt");

  if (fin.fail()) //catch file exception
  {
    cout << "Unable to open file";
    exit(1);
  }

  while (getline(fin, txt)) //get the first line of the input file
  {
    txt = txt;
    i = 0;
    firstWord = true;

    while (i < txt.length())
    {
      word = "";

      if (txt.at(i) == ' ')
      {
        fout << txt.at(i);
        firstWord = false;
        i++;
      } else
      {
        if (txt.find(" ", i) == -1)
        {
          endOfWord = txt.length() - i;
        } else
        {
          endOfWord = txt.find(" ", i);
          endOfWord -= i;
        }

        for (int l = i; l < endOfWord + i; l++)
        {
          word += txt.at(l);
        }

        i += word.length();

        word = quasiLatinGenerator(word, firstWord);

        fout << word;
      }
    }
    fout << endl;
  }

  fin.close();
  fout.close();

  return 0;
}

bool isVowel(char vowelOrNah) //check if inputted char is a vowel
{
  if (vowelOrNah == 'y' || vowelOrNah == 'a' || vowelOrNah == 'e' || vowelOrNah == 'i' || vowelOrNah == 'o' || vowelOrNah == 'u' || vowelOrNah == 'Y' || vowelOrNah == 'A' || vowelOrNah == 'E' || vowelOrNah == 'I' || vowelOrNah == 'O' || vowelOrNah == 'U')
  {
    return true;
  } else
  {
    return false;
  }
}

char capitalize(char txt) //capitalize inputted char
{
  char newTxt = txt;
  if (int(txt) >= 97 && int(txt) <= 122)
  {
    newTxt = int(txt) - 32;
  }

  return newTxt;
}

char lowercase(char txt) //lowercase inputted char
{
  char newTxt = txt;
  if (int(txt) >= 65 && int(txt) <= 90)
  {
    newTxt = int(txt) + 32;
  }

  return newTxt;
}

string quasiLatinGenerator(string word, bool firstWord) //main function that controls what is done to the current word
{
  if (word.length() <= 1)
  {
    return word;
  } else

  if (isVowel(word.at(0)))
  {
    word = startsWithVowel(word, firstWord);
    return word;
  } else

  if (!isVowel(word.at(0)) && !isVowel(word.at(1)))
  {
    word = twoConsonants(word, firstWord);
    return word;
  } else

  if (!isVowel(word.at(0)) && isVowel(word.at(1)))
  {
    word = consonantVowel(word, firstWord);
    return word;
  } else

  return word;
}

string consonantVowel(string word, bool firstWord) //function that handles words with a consonant followed by a vowel
{
  char swap, swapEnd = '\0';
  bool wasCapital = false;

  if (int(word.at(0)) >= 65 && int(word.at(0)) <= 90)
  {
    wasCapital = true;
  }

  if (word.at(word.length() - 1) < 65 || (word.at(word.length() - 1) > 90 && word.at(word.length() - 1) < 97) || word.at(word.length() - 1) > 122)
  {
    swapEnd = word.at(word.length() - 1);
    word.erase(word.begin() + (word.length() - 1));
  }

  swap = lowercase(word.at(0));

  word.erase(word.begin());

  word = word + swap + "oi" + swapEnd;

  if (firstWord || wasCapital)
  {
    word.at(0) = capitalize(word.at(0));
  }

  return word;
}

string twoConsonants(string word, bool firstWord) //function that handles words that start with two consonants
{
  char swap, swap2, swapEnd = '\0';
  bool wasCapital = false;

  if (int(word.at(0)) >= 65 && int(word.at(0)) <= 90)
  {
    wasCapital = true;
  }

  if (word.at(word.length() - 1) < 65 || (word.at(word.length() - 1) > 90 && word.at(word.length() - 1) < 97) || word.at(word.length() - 1) > 122)
  {
    swapEnd = word.at(word.length() - 1);
    word.erase(word.begin() + (word.length() - 1));
  }

  swap = lowercase(word.at(0));
  swap2 = word.at(1);

  word.erase(word.begin());
  word.erase(word.begin());

  word = word + swap + swap2 + "ah" + swapEnd;

  if (firstWord || wasCapital)
  {
    word.at(0) = capitalize(word.at(0));
  }

  return word;
}

string startsWithVowel(string word, bool firstWord) //function that handles words that start a vowel
{
  char swapEnd = '\0';
  bool wasCapital = false;

  if (int(word.at(0)) >= 65 && int(word.at(0)) <= 90)
  {
    wasCapital = true;
  }

  if (word.at(word.length() - 1) < 65 || (word.at(word.length() - 1) > 90 && word.at(word.length() - 1) < 97) || word.at(word.length() - 1) > 122)
  {
    swapEnd = word.at(word.length() - 1);
    word.erase(word.begin() + (word.length() - 1));
  }

  word = word + "eeh" + swapEnd;

  if (firstWord || wasCapital)
  {
    word.at(0) = capitalize(word.at(0));
  }

  return word;
}
