// File Seq.h
// Header file for a simple linked-list implementation of a Sequence class
class Seq{
public:
   // Constructors and Destructors
   Seq(); //default construtor
   Seq(const Seq& set); //copy constructor
   ~Seq(); //destructor

   // Adds element data to the front of the sequence.
   void add(int data);

   // Adds element data at indes pos.
   void insertAt(int data, int pos);
   // All existing 
   // Precondition: The sequence is already of length at least pos.
	
   bool remove(int data );
   // removes data from the sequence.
   // makes no change if data is not in the sequence
   // returns true iff data was in the sequence, and has been removed

   void display();
   // prints the sequence ot the screen, as a comma-separated list.

private:
   // A struct is like a class that has no functions/methods. 
   // It has data members, which are accessed using the same notaiton as for classes.
   // List node
   struct Node {
      int data; //list data
      Node *next; //pointer to next item in the list
   };

   Node * first; //Pointer to the first node in the list
   int size; //Records the number of nodes in the list
};
