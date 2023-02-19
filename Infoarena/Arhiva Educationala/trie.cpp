#include <fstream>
#include <string>

using namespace std;

const int INF = 0x3f3f3f3f;

ifstream fin("trie.in");
ofstream fout("trie.out");

class Trie
{
public:
    Trie *children[26];

    int nrEnding = 0;
    int subTreeWordCount = 0;

    void insert(string &s, int k)
    {
        if (k >= s.size())
        {
            nrEnding++;
            return;
        }

        char c = s[k] - 'a';

        if (children[c] == NULL)
            children[c] = new Trie();

        subTreeWordCount++;
        children[c]->insert(s, k + 1);
    }

    void remove(string &s, int k, bool &didRemove)
    {
        if (k >= s.size())
        {
            didRemove = true;
            nrEnding--;
            return;
        }

        char c = s[k] - 'a';

        if (children[c] == NULL)
            return;

        if (children[c]->subTreeWordCount == 0 && children[c]->nrEnding == 0)
            return;

        children[c]->remove(s, k + 1, didRemove);
        if (didRemove)
            subTreeWordCount--;
    }

    int count(string &s, int k)
    {
        if (k == s.size())
            return nrEnding;

        char c = s[k] - 'a';

        if (children[c] == NULL)
            return 0;

        return children[c]->count(s, k + 1);
    }

    int longestPrefix(string &s, int k)
    {

        char c = s[k] - 'a';

        if (k == s.size() || children[c] == NULL)
            return k;

        if (children[c]->nrEnding == 0 && children[c]->subTreeWordCount == 0)
            return k;

        return children[c]->longestPrefix(s, k + 1);
    }
};

Trie trie;

int main()
{
    string s;
    int c;
    while (fin >> c >> s)
    {
        if (c == 0)
            trie.insert(s, 0);
        if (c == 1)
        {
            bool didRemove = false;
            trie.remove(s, 0, didRemove);
        }
        if (c == 2)
            fout << trie.count(s, 0) << "\n";

        if (c == 3)
            fout << trie.longestPrefix(s, 0) << "\n";
    }

    return 0;
}
