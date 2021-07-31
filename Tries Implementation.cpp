#include<iostream>
#include<algorithm>
using namespace std;

class tries{
public:
    tries *child[26];
    bool isend;

    tries(){
        for(int i=0;i<26;++i)
            child[i]=nullptr;
        isend=0;
    }


    bool insertTrie(string a, tries* root){
        if(!all_of(a.begin(), a.end(), [](char i) { return (i >= 'a' && i <= 'z'); })){
            cout<<"CHARACTERS OUT OF RANGE!"<<endl;
            return 0;
        }

        tries* curr=root;
        for(int i=0;i<a.size();++i)
        {
            int index=a[i]-'a';
            if(curr->child[index]==nullptr)
                curr->child[index]=new tries();
            curr=curr->child[index];
        }
        curr->isend=1;
        return 1;
    }


    bool searchTrie(string a, tries* root){
        if(!(all_of(a.begin(),a.end(),[](char i){return i>='a'&&i<='z';}))){
            cout<<"CHARACTERS OUT OF RANGE!"<<endl;
            return 0;
        }
        tries* curr=root;
        for(int i=0;i<a.size();++i){
            int index=a[i]-'a';
            if(curr->child[index]==nullptr)
            return 0;
        curr=curr->child[index];
        }
        return curr->isend;
    }


};

int main(){
    tries* root=new tries();
    cout<<"Make selection:"<<endl;
    cout<<"1. Insert a string (only in small caps)"<<endl;
    cout<<"2. Search a string "<<endl;

    int n;
    while(cin>>n)
    {
        cout<<"Enter string of choice:"<<endl;
        string a;
        cin>>a;

        switch(n)
        {
        case 1:
            if(root->insertTrie(a,root))
             cout<<"INSERTED!"<<endl;
            else
                cout<<"COULDN'T INSERT!"<<endl;
            break;

        case 2:
           if( root->searchTrie(a,root))
            cout<<"FOUND MATCH!"<<endl;
           else
            cout<<"COUNDN'T FIND A MATCH!"<<endl;
            break;

        default:
            cout<<"Invalid Choice!!"<<endl;
        }


    }
}
