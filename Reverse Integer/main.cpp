#include <iostream>

using namespace std;

void reverseStr(string& str)
{
    int n = str.length();

    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}
int main()
{
    int n;
    cin>>n;
    string ch=to_string(n);
    reverseStr(ch);
    cout<<ch;
    return 0;
}
