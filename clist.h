
#ifdef __cplusplus
extern "C"
{
#endif

#define USE_STRUCT HANDLE

#ifdef USE_STRUCT_HANDLE
		typedef struct clist_ *clist;
#else
		typedef int clist;
#endif

		clist create_list();
		
		void push_back(clist list,int data);

		void push_front(clist list,int data);

		void print(clist list);

		int element_at(clist list,int i);

		int size(clist list);

		int test(clist,int);

#ifdef __cplusplus		
}
#endif
