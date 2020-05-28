#include <bits/stdc++.h>

using namespace std;


// заполнение контейнера

template<typename Containter>
void fillRandom(Containter &cont, int n) {
    for (int i = 0, r; i < n; i++) {
        r = rand();
        cont.insert(cont.end(), r);
    }
}

template<class Elem_first, class Elem_second>
void fillRandom(map<Elem_first, Elem_second> &cont, int n) {
    for (int i = 0, r; i < n; i++) {
        r = rand();
        auto p = make_pair(r, r);
        cont.insert(cont.end(), p);
    }
}

// вывод содержимого в консоль

template<typename Containter>
void show(Containter &cont) {
    for (auto i : cont)
        cout << i << " ";
    cout << endl << endl;
}

template<class Elem_first, class Elem_second>
void show(map<Elem_first, Elem_second> &cont) {
    for (auto i : cont)
        cout << "(" << i.first << "," << i.second << ") ";
    cout << endl << endl;
}

int main() {
    int n = 15;

    long long start_time_vec = clock();
    cout << "vector : ";
    vector<int> v1;
    fillRandom(v1, n);
    sort(v1.begin(), v1.end());
    show(v1);
    vector<int> v2;
    fillRandom(v2, n);
    sort(v2.begin(), v2.end());
    show(v2);
    for (int i = 0; i < v2.size(); ++i)
        v1.push_back(v2[i]);
    sort(v1.begin(), v1.end());
    show(v1);
    long long end_time_vec = clock();

    long long start_time_list = clock();
    cout << "list : ";
    list<int> l1;
    fillRandom(l1, n);
    l1.sort();
    show(l1);
    list<int> l2;
    fillRandom(l2, n);
    l2.sort();
    show(l2);
    for (auto i = l2.begin(); i != l2.end(); ++i)
        l1.push_back(*i);
    l1.sort();
    show(l1);
    long long end_time_list = clock();


    long long start_time_ms = clock();
    cout << "multsrt : ";
    multiset<int> ms1;
    fillRandom(ms1, n);
    show(ms1);
    multiset<int> ms2;
    fillRandom(ms2, n);
    show(ms2);
    for (auto i = ms2.begin(); i != ms2.end(); ++i)
        ms1.insert(*i);
    show(ms1);
    long long end_time_ms = clock();


    long long start_time_map = clock();
    cout << "map : ";
    map<int, int> m1;
    fillRandom(m1, n);
    show(m1);
    map<int, int> m2;
    fillRandom(m2, n);
    show(m2);
    for (auto i = m2.begin(); i != m2.end(); ++i)
        m1.insert(*i);
    show(m1);
    long long end_time_map = clock();


    cout << "vector : " << end_time_vec - start_time_vec << '\n';
    cout << "list : " << end_time_list - start_time_list << '\n';
    cout << "multiset : " << end_time_ms - start_time_ms << '\n';
    cout << "map : " << end_time_map - start_time_map << '\n';
    return 0;
}