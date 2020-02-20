
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
    double valueToTime;

};
vector<int> getData(Library lib,int n){
    vector<int> result;
    for(int i =0 ;i <lib.books.size() && n;i++)
    {
        int book =  lib.books[i];
       if(! visited[book])
       {
        result.push_back(book);
        visited[book]=1;
        n--;
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
        if(a.valueToTime < b.valueToTime)
             return a.valueToTime > b.valueToTime;
             else //if (a.signupDays == b.signupDays)
                return a.signupDays < b.signupDays;
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
            double sum=0;
        for(int k = 0 ;k< newOne.books.size() && k < 15;k++)
            sum+=newOne.books[k];
        newOne.valueToTime = sum/(newOne.signupDays * 25);
        adj[i] = newOne;
    }
    // Lets work
    sort(adj.begin(),adj.end(),comp);
    int days = 0;
    int i;
    int x =0;
    for( i= 0 ;i < libraries && days < finishDays;i++)
    {
        vector<int> res = getData(adj[i], (finishDays- days)*adj[i].numberCanPrint );
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
    int count = 0;
    //process

    return 0;
}
