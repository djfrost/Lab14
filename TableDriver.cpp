#include "TableSortedList.h"
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;
#include "CD.h"
using CSC2110::CD;
#include "Text.h"
using CSC2110::String;

#include <iostream>
using namespace std;

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
   }
   delete iter;
}

int main()
{
   ListArray<CD>* cds = CD::readCDs("cds.txt");
   int num_items = cds->size();
   cout << num_items << endl;

   TableSortedList<CD>* slt = new TableSortedList<CD>(&CD::compare_items, &CD::compare_keys);

	ListArrayIterator<CD>* iter = slt->iterator();
	int count = 0;
	while(iter->hasNext())
	{
		CD* cd = iter->next();
		cds[count] = cd;
		count++;
	}
	delete iter;
   //DO THIS
   //thoroughly test your table
	
	

	while(!slt->isEmpty())
	{
		slt->remove();
	}


   deleteCDs(cds);
   delete cds;
   delete slt;
   return 0;
}
