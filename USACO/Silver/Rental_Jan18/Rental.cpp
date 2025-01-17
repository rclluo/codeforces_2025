/*
Sort the cows, and farmers in descending order. 
Also sort the shops in descending order by the price of milk.
For each cow, if it can make more money by selling milk, sell it.
Else, rent it to a farmer.
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin("rental.in");
    ofstream cout("rental.out");
	int n, m, r;
	cin >> n >> m >> r;
	vector<int> milk(n);
	for (int i=0; i<n; i++) { 
        cin >> milk[i]; 
    }
	sort(milk.begin(), milk.end(), greater<int>());
	vector<pair<int, int>> shops(m);
	for (int i=0; i<m; i++) { 
        cin >> shops[i].second >> shops[i].first; 
    }
	sort(shops.begin(), shops.end(), greater<pair<int,int>>());
	vector<int> rental_prices(r);
	for (int i=0; i<r; i++) { 
        cin >> rental_prices[i]; 
    }
	sort(rental_prices.begin(), rental_prices.end(), greater<int>());
	int shop=0;
	int curr_rental=0;
	int curr_cow=0;
	long long ans=0;
	while (curr_cow<n) {
		int amt=milk[curr_cow];
		int sold_money=0;
		int curr_shop=shop;
		int last=0;
		while (curr_shop<m) {
			int sold=min(amt, shops[curr_shop].second);
			sold_money +=shops[curr_shop].first*sold;
			amt -= sold;
			if (amt == 0) {
				last=sold;
				break;
			} else {
				curr_shop++;
			}
		}
		if (curr_rental >= r || sold_money>rental_prices[curr_rental]) {
			ans += sold_money;
			shop=curr_shop;
			if (shop<m) { 
                shops[shop].second -= last; 
            }
			curr_cow++;
		} else {
			ans +=rental_prices[curr_rental];
			n--;
			curr_rental++;
		}
	}
    cout << ans;
}