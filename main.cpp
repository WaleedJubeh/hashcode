
#include<bits/stdc++.h>
using namespace std;
int visited[1000009];
int scores[1000009];
vector<pair<int,int> > scoresIndex;
struct Library{
    int id;
    int signupDays;
    int numberCanPrint;
    vector<int> books;

};
vector<int> getData(Library lib){
    vector<int> result;
    for(int i =0 ;i <lib.books.size();i++)
    {
        int book =  lib.books[i];
       if(! visited[book])
       {
        result.push_back(book);
        visited[book]=1;
       }
    }
    return result;
}
bool maxScore(int a , int b)
{
    return scores[a] < scores[b];
}
bool comp(Library a, Library b)
    {
        if(a.signupDays > b.signupDays)
             return a.signupDays < b.signupDays;
        else if (a.signupDays == b.signupDays)
                return a.books.size() > b.books.size();
    }
vector<Library > adj;

int main() {
    freopen("f_libraries_of_the_world.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int libraries,books,finishDays;
    cin>>books>>libraries>>finishDays;
    adj.resize(libraries);
    scoresIndex.resize(books);
    int score;

    for(int i =0 ;i < books; i++)
    {
        cin>>score;
        scores[i]= score;
        scoresIndex[i].first = score;
        scoresIndex[i].second = i;
    }
    int booksNum,signupdays,howCan;
    for(int i =0 ; i< libraries ;i++)
    {

        cin>>booksNum>>signupdays>>howCan;
        Library newOne;
        newOne.id = i;
        newOne.numberCanPrint=howCan;
        newOne.signupDays=signupdays;
        int book;
        for(int j =0 ;j<booksNum ;j++)
        {
            int book;
            cin>>book;
            newOne.books.push_back(book);
        }
        sort(newOne.books.rbegin(),newOne.books.rend(),maxScore);
        adj[i] = newOne;
    }
    // Lets work
    sort(adj.begin(),adj.end(),comp);
    int days = 0;
    int i;
    int x =0;
    for( i= 0 ;i < libraries && days < finishDays;i++)
    {
        vector<int> res = getData(adj[i]);
        if(res.size() == 0)
            continue;

        days += adj[i].signupDays;

        x++;
        cout<<adj[i].id <<" "<<res.size()<<endl;
        for(int i = 0 ;i < res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    cout<<x<<endl;
    //process

    return 0;
}
