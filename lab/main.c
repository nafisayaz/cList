
#include <stdio.h>
#include "../clist.h"

int main()
{
		clist list = create_list();

		printf("Total elements: ");
		int n;
		scanf("%d",&n);
		int i;
		printf("elements: ");
		for(i=0;i<n;i++)
		{
				int data;
				scanf("%d",&data);
				push_back(list,data);
		}
		for(i=0;i<size(list);i++)
			printf("%d ",element_at(list,i));
		printf("\n");

			printf(" %d ",element_at(list,3));
			printf(" %d ",element_at(list,2));
			printf(" %d ",element_at(list,-2));
			printf(" %d ",element_at(list,-1));
}
