class Solution {
public:
    bool halvesAreAlike(string s) {
        std::string firstHalf = s.substr(0, s.length()/2);
        std::string secondHalf = s.substr(s.length()/2);
        int vowelsFirstHalf = 0;
        int vowelSecondHalf = 0;
        int vowelsTotal = 0;
    for(int i = 0; firstHalf[i]!='\0'; ++i) {
        if(firstHalf[i]=='a' || firstHalf[i]=='e' || firstHalf[i]=='i' ||
           firstHalf[i]=='o' || firstHalf[i]=='u' || firstHalf[i]=='A' ||
           firstHalf[i]=='E' || firstHalf[i]=='I' || firstHalf[i]=='O' ||
           firstHalf[i]=='U')
        {
            ++vowelsFirstHalf;
        }
    }
        cout << "Vowels: " << vowelsFirstHalf << endl;

     for(int i = 0; secondHalf[i]!='\0'; ++i) {
        if(secondHalf[i]=='a' || secondHalf[i]=='e' || secondHalf[i]=='i' ||
           secondHalf[i]=='o' || secondHalf[i]=='u' || secondHalf[i]=='A' ||
           secondHalf[i]=='E' || secondHalf[i]=='I' || secondHalf[i]=='O' ||
           secondHalf[i]=='U')
        {
            ++vowelSecondHalf;
        }
    }
        cout << "Vowels: " << vowelSecondHalf << endl;

    if (vowelsFirstHalf == vowelSecondHalf) {
        return true;
    } else {
        return false;
    }
       
        cout << s.length() << " : " << s << endl;
        cout << firstHalf.length()  << " : " << firstHalf << endl;
        cout << secondHalf.length()  << " : " << secondHalf  << endl;
    

        
    }
};
