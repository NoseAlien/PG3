#include <stdio.h>
#include <list>
#include <vector>

int main()
{
	std::list<const char*> yamanoteLine
	{
		"Tokyo","Kanda","Akihabara","Okachimachi",
		"Ueno","Uguisudani","Nippori","Tabata","Komagome",
		"Sugamo","O-tsuka","Ikebukuro","Mejiro","Takadanobaba",
		"Shin_O-kubo","Shinjuku","Yoyogi","Harajuku",
		"Shibuya","Ebisu","Meguro","Gotanda","O-saki",
		"Shinagawa","Tamachi","Hamamatsucho-","Shinbashi",
		"Yurakucho-"
	};

	printf("1970\n");
	for (const auto& station : yamanoteLine)
	{
		printf("%s, ", station);
	}
	printf("\n\n");

	for (std::list<const char*>::iterator itr = yamanoteLine.begin(); itr != yamanoteLine.end(); ++itr)
	{
		if (*itr == "Tabata")
		{
			itr = yamanoteLine.insert(itr, "Nishi_Nippori");
			itr++;
		}
	}

	printf("2019\n");
	for (const auto& station : yamanoteLine)
	{
		printf("%s, ", station);
	}
	printf("\n\n");

	for (std::list<const char*>::iterator itr = yamanoteLine.begin(); itr != yamanoteLine.end(); ++itr)
	{
		if (*itr == "Tamachi")
		{
			itr = yamanoteLine.insert(itr, "Takanawa_Gateway");
			itr++;
		}
	}

	printf("2022\n");
	for (const auto& station : yamanoteLine)
	{
		printf("%s, ", station);
	}
	printf("\n\n");

	return 0;
}