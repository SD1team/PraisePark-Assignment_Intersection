#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <set>

void makeRandomData(int rangeOfRandom_begin, int rangeOfRandom_end, 
					int sizeOfData, 
					std::set<int>* randNumSet, char* fileName) {

	FILE * file = fopen(fileName, "w");

	if(file != NULL) {

		int randNum;

		do {
			randNum = ((rand()<<5) | rand()) % rangeOfRandom_end + rangeOfRandom_begin; // ((rand()<<5) | rand()) -> 0 ~ 1,048,575

			if((*randNumSet).insert(randNum).second) {
				fprintf(file, "%d\n", randNum);
			}

		} while((*randNumSet).size() < sizeOfData);

		fclose(file);
	}
}

void makeIntersectionData(std::set<int>* setA, std::set<int>* setB, char* fileName) {

	if((*setA).size() < (*setB).size()) {
		makeIntersectionData(setB, setA, fileName);
		return;
	}

	FILE* file = fopen(fileName, "w");

	if(file != NULL) {

		std::set<int>::iterator b_it, a_it;

		for(b_it = (*setB).begin(); b_it != (*setB).end(); ++b_it) {

			a_it = (*setA).find(*b_it);
			
			if(a_it != (*setA).end()) {
				fprintf(file,"%d\n", *a_it);
			}

			/*if((*setA).find(*b_it) != (*setA).end()) {
				fprintf(file,"%d\n", *(*setA).find(*b_it));
			}*/
		}

		fclose(file);
	}
}

int main() {

	std::set<int> setA, setB;

	srand((unsigned)time(NULL));

	makeRandomData(1, 1000000, 100000, &setA, "A.txt");
	makeRandomData(1, 1000000, 1000, &setB, "B.txt");

	makeIntersectionData(&setA, &setB, "R.txt");

	return 0;
}