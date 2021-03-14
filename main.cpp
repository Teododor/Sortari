#include <bits/stdc++.h>
using namespace std;
ifstream fin("teste.in");
ofstream fout("teste.out");
ofstream G("timpi.out");
vector<int> v;
int n,ct,COPIE_N;

void bubble_sort(vector<int> v)
{
    int sortat = 0;
    while (!sortat)
    {
        sortat = 1;
        for (int i = 0; i < v.size() - 1; i++)
            if (v[i] > v[i + 1])
            {
                swap(v[i], v[i + 1]);
                sortat = 0;
            }
    }
}

//int valoare_pivot(int lo,int hi,int opt)
//{
//    if(opt==1) return (lo+hi)/2;
//   else if(opt==2) return lo+rand()%(hi-lo+1);
//   else if(opt==3)
//   {
//       int mij=(lo+hi)/2, minn=min(v[lo],min(v[mij],v[hi])), maxx=max(v[lo],max(v[mij],v[hi]));
//       if(v[mij]!=minn && v[mij]!=maxx) return mij;
//       else if(v[lo]!=minn && v[lo]!=maxx) return lo;
//       else return v[hi];
//   }
//}
void quicksort_mij(vector<int> v,int lo,int hi)
{
    if(lo>hi)return;
    int st,dr,mij,pivot;
    st=lo;
    dr=hi;
    mij=(st+dr)/2;

    pivot=v[mij];

    do
    {
        while(v[st]<pivot) st++;
        while(v[dr]>pivot) dr--;
        if(st<=dr)
        {
            swap(v[st],v[dr]);
            st++;
            dr--;
        }
    }
    while(st<dr);

    if(lo<dr)  quicksort_mij(v,lo,dr);
    if(st<hi) quicksort_mij(v,st,hi);
}
void quicksort_rand(vector<int> v,int lo,int hi)
{
    if(lo>hi)return;
    int st,dr,mij,pivot;
    st=lo;
    dr=hi;
    //mij=(st+dr)/2;

    pivot=v[lo+rand()%(hi-lo+1)];

    do
    {
        while(v[st]<pivot) st++;
        while(v[dr]>pivot) dr--;
        if(st<=dr)
        {
            swap(v[st],v[dr]);
            st++;
            dr--;
        }
    }
    while(st<dr);

    if(lo<dr)  quicksort_rand(v,lo,dr);
    if(st<hi) quicksort_rand(v,st,hi);
}
void quicksort_3(vector<int> v,int lo,int hi)
{
    if(lo>hi)return;
    int st,dr,pivot;
    st=lo;
    dr=hi;
    int mij=(lo+hi)/2, minn=min(v[lo],min(v[mij],v[hi])), maxx=max(v[lo],max(v[mij],v[hi]));
//       int mij=(lo+hi)/2, minn=min(v[lo],min(v[mij],v[hi])), maxx=max(v[lo],max(v[mij],v[hi]));
//       if(v[mij]!=minn && v[mij]!=maxx) return mij;
//       else if(v[lo]!=minn && v[lo]!=maxx) return lo;
//       else return v[hi];

    if(v[mij]!=minn && v[mij]!=maxx) pivot=v[mij];
    else if(v[lo]!=minn && v[lo]!=maxx) pivot=v[lo];
    else pivot=v[hi];
    do
    {
        while(v[st]<pivot) st++;
        while(v[dr]>pivot) dr--;
        if(st<=dr)
        {
            swap(v[st],v[dr]);
            st++;
            dr--;
        }
    }
    while(st<dr);

    if(lo<dr)  quicksort_3(v,lo,dr);
    if(st<hi) quicksort_3(v,st,hi);
}
void mergeSort(vector<int> v,int lo,int hi)
{
    vector<int> aux(COPIE_N);
    if(lo>=hi)return;
    int i,j,k, mi=(lo+hi)/2;
    mergeSort(v,lo,mi);
    mergeSort(v,mi+1,hi);
    for(i=lo; i<=hi; i++)aux[i]=v[i];
    i=lo;
    k=lo;
    j=mi+1;
    while(i<=mi&&j<=hi)
    {
        if(aux[i]<=aux[j])v[k++]=aux[i++];
        else v[k++]=aux[j++];
    }
    while(i<=mi)v[k++]=aux[i++];
    while(j<=hi)v[k++]=aux[j++];

}

void count_sort(vector<int> v)
{
    if(ct==4 || ct==5 || ct==6 || ct==7) return;
    int maxx = 0;
    for (auto &it:v)
        maxx = max(maxx, it);
    vector<int> c(maxx + 1, 0), output(v.size());
    for (auto &it:v)
        c[it]++;
    for (int i = 1; i < v.size(); i++)
        c[i] += c[i - 1];
    for (auto &it:v)
    {

        output[c[it] - 1] = it;
        c[it]--;
    }
    //  for (int i = 0; i < output.size(); i++)
    // cout << output[i] << ' ';

    // cout << endl;
//    cout<<"AFISAREA DIN FUNCTIE:  ";
//
//    for (auto &it:output)
//        cout << it << ' ';
//    cout<<endl<<endl;


}                            /// ultimul element nu este afisat in ordine

void radix_256(vector<int> v)
{
    vector <int> locuri[256];
    int p=0, mask=255, sortat=0;
    while(!sortat)
    {
        sortat=1;
        for(auto &it:v)
        {
            int ult = (it>>p) &mask ;
            locuri[ult].push_back(it);
        }
        int poz=0;
        for(auto &it:locuri)
        {
            for(auto &j:it)
            {
                v[poz]=j;
                if(poz>0 && v[poz]<v[poz-1])
                    sortat=0;
                poz++;
            }
            it.clear();
        }
        p+=8;
    }
}

void radix_10(vector<int> v)
{
    vector<int> locuri[10];
    int p=1, sortat=0;
    while(!sortat)
    {
        sortat=1;
        for(auto &it:v)
        {
            int ultcif=(it/p)%10;
            locuri[ultcif].push_back(it);
        }
        int poz=0;
        for(auto &it:locuri)
        {
            for(auto &j:it)
            {


                v[poz]=j;
                if(poz>0 && v[poz]<v[poz-1])
                    sortat=0;
                poz++;
            }

            it.clear();
        }
        p*=10;
    }
}
void sortare_STL(vector<int> v)
{
    sort(v.begin(),v.end());
}
void sortare_2_foruri(vector<int> v)
{
    for(int i=0;i<v.size()-1;i++)
        for(int j=i+1;j<v.size();j++)
            if(v[i]>v[j])
                swap(v[i],v[j]);
}

int verifica_sortat(vector <int> v)
{
    for(int i=1;i<v.size()-1;i++)
        if(v[i]<v[i-1])
        return 0;
    return 1;
}
int main()
{

    srand(time(NULL));
    int nr_teste;
    fin>>nr_teste;
    for(;nr_teste;nr_teste--)
    {
        ct++;
        G<<"Pentru testul "<<ct<<" avem timpii :   "<<endl<<endl;
        G<<"Testul "<< ct << "este testul in care: ";
        if(ct==1) G<<"avem 1000 numere random";
        if(ct==2) G<<"avem 10000 numere random mai mari ca 1000000";
        if(ct==3) G<<"avem 10000 numere random";
        if(ct==4) G<<"avem 50000 numere egale";
        if(ct==5) G<<"avem 10000 numere random";
        if(ct==6) G<<"avem 100000 numere random";
        if(ct==7) G<<"avem 200000 numere de tip munte, prima jumatate crescatoare, a doua jumatate descrescatoare";



        G<<endl<<endl;
        fin>>n;
        COPIE_N=n;
        for(;n;n--)
        {
            int x;
            fin>>x;
            v.push_back(x);
        }

        auto start1 = chrono::high_resolution_clock::now();
        bubble_sort(v);
        auto stop1 = chrono::high_resolution_clock::now();
        auto duration1 = chrono::duration_cast<chrono::microseconds>(stop1 - start1);
        G<<"Bubble sort a rulat in "<<duration1.count()<<endl;

        auto start2 = chrono::high_resolution_clock::now();
        quicksort_rand(v,0,v.size()-1);
        auto stop2 = chrono::high_resolution_clock::now();
        auto duration2 = chrono::duration_cast<chrono::microseconds>(stop2 - start2);
        G<<"Quick sort cu pivot in mijloc a rulat in "<<duration2.count()<<endl;

        auto start3 = chrono::high_resolution_clock::now();
        quicksort_rand(v,0,v.size()-1);
        auto stop3 = chrono::high_resolution_clock::now();
        auto duration3 = chrono::duration_cast<chrono::microseconds>(stop3 - start3);
        G<<"Quick sort cu pivot random a rulat in "<<duration3.count()<<endl;

        auto start4 = chrono::high_resolution_clock::now();
        quicksort_3(v,0,v.size()-1);
        auto stop4 = chrono::high_resolution_clock::now();
        auto duration4 = chrono::duration_cast<chrono::microseconds>(stop4 - start4);
        G<<"Quicksort cu mediana in 3 a rulat in "<<duration4.count()<<endl;

        auto start5 = chrono::high_resolution_clock::now();
        mergeSort(v,0,v.size()-1);
        auto stop5 = chrono::high_resolution_clock::now();
        auto duration5 = chrono::duration_cast<chrono::microseconds>(stop5 - start5);
        G<<"Merge sort a rulat in  "<<duration5.count()<<endl;

        auto start6 = chrono::high_resolution_clock::now();
        count_sort(v);
        auto stop6 = chrono::high_resolution_clock::now();
        auto duration6 = chrono::duration_cast<chrono::microseconds>(stop6 - start6);
        G<<"Count sort a rulat in "<<duration6.count()<<endl;

        auto start7 = chrono::high_resolution_clock::now();
        radix_10(v);
        auto stop7 = chrono::high_resolution_clock::now();
        auto duration7 = chrono::duration_cast<chrono::microseconds>(stop7 - start7);
        G<<"Radix sort cu baza 10 a rulat in "<<duration7.count()<<endl;

        auto start8 = chrono::high_resolution_clock::now();
        radix_256(v);
        auto stop8 = chrono::high_resolution_clock::now();
        auto duration8 = chrono::duration_cast<chrono::microseconds>(stop8 - start8);
        G<<"Radix sort cu baza 256 a rulat in "<<duration8.count()<<endl;

        auto start9 = chrono::high_resolution_clock::now();
        sortare_STL(v);
        auto stop9 = chrono::high_resolution_clock::now();
        auto duration9 = chrono::duration_cast<chrono::microseconds>(stop9 - start9);
        G<<"Sotrl din STL a rulat in "<<duration9.count()<<endl;

        auto start10 = chrono::high_resolution_clock::now();
        sortare_2_foruri(v);
        auto stop10 = chrono::high_resolution_clock::now();
        auto duration10 = chrono::duration_cast<chrono::microseconds>(stop10 - start10);
        G<<"Sort-ul cu 2 for-uri a rulat in "<<duration10.count()<<endl;



        v.clear();
    }
   return 0;
}
