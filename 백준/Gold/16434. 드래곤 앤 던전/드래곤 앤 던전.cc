#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 123987
#define ll long long int
#define MONSTER 1
#define POTION 2
typedef struct datas {
	ll d;
	ll a;
	ll h;
}datas;
datas hero;
datas maxHero;
ll n, a;
ll cnt;
void input() {
	cin >> n >> hero.a;

	hero.h = 0; maxHero.h = 0;
	
}
ll solve() {

	for (ll i = 0; i < n; i++) {
		ll d, a, h;
		cin >> d >> a >> h;
		if(d == MONSTER) {
			
			hero.h += a * ((h / hero.a) - (h % hero.a != 0 ? 0 : 1));
			maxHero.h = max(maxHero.h, hero.h);
		} else {
			hero.a += a;
			hero.h = max(hero.h - h, (ll)0);
			
		}
	
	}
	maxHero.h++;
	return maxHero.h;
}
int main() {
	cin.tie(); ios::sync_with_stdio(0);
	input();
	cout << solve();
}
