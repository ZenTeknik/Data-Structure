              // LINK LIST DATA STRUCTURE
 // array in alloacted in contigous memory
 // while the link list is not contigous memory
 // but, array have an issue with a size  on the othe hand in link list we dont have an issue with memory we have enough memory 

// For arrays we just need data not address 
// for link list we need both address and data 
// In link list first we have to approcah first then we can go to second    by using address 

// linked list is a data structure in which elemenrs are explicitly ordered , that is each item conatains within itself the address of next item 

//  Node is mixture of somthings 
// it have two part  object and next (object is the data ,next is the address of another like another box )
// but, the node is contigoues (object and next)
 
 
 // searching is always be start form the head of the list (first node)



struct node {
char name[15];
node *next; 
};  
// here *next is the self refrential pointer (withou t pointer the compiler gives an error  bcz, we are creating object  while the defination is not completed)


// Features
// we have an head otherwise we dont know which is our first node
//we have current pointer not a current index 
// next field in the last points to nothing. we will place NULL.
// (int next of the last node )


