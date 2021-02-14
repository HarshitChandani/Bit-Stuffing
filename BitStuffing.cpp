/**
 * Program to implement Bit stuffing ( linear Linked list has been used to implement bit stuffing .  )
 *  
*/

#include <iostream>
using namespace std;
struct NODE{
   bool data;
   NODE * next ; 
};
NODE *head = NULL , *king = NULL;
class BitStuffing{
   public:
      int countNode = 0;
      NODE * createNode(bool data){
         NODE *newNode = new NODE;
         newNode->data = data;
         newNode->next = NULL;  
         return newNode;
      }
      void Insertion(bool data){
         NODE *tmpNode = createNode(data);
         if(head == NULL){
            head = king = tmpNode;
         }
         else{
            head->next = tmpNode;
            head = head->next;
         }
         countNode += 1; 
      }
      void display(){
         NODE * tmpNode = king;
         while(tmpNode != head){
            cout <<tmpNode->data;
            tmpNode = tmpNode->next;
         }
         cout<<tmpNode->data;
         cout<<endl;
      }
      void bit_stuffing(){
         NODE * current = NULL;
         NODE * pointer = new NODE;
         current = king;
         while(current != head)
         {
               if(current->data == 1)
               {
                  int count = 0;
                  pointer = current;
                  for(int i=0; i<=4; i++){
                     if(pointer->data == 1)
                     {
                        count +=1;
                        if(pointer->next == NULL){
                           break;
                        }else{
                           if(count == 5){
                              break;
                           }
                           else{
                              pointer = pointer->next;
                           }
                        }
                     }
                  }
                  if(count == 5)
                  {
                     NODE * tmpNode1 = new NODE;
                     tmpNode1->data = 0;
                     tmpNode1->next =pointer->next;       
                     pointer->next = tmpNode1;
                     if(tmpNode1->next != NULL){
                        current = tmpNode1->next;
                     }else{
                        head= current = tmpNode1 ;
                     }
                  }
                  else{
                     current = pointer;
                  }
               }
               else{
                  current = current->next;
               }
            }
      }  
};
int main(){
   BitStuffing BS;
   int frameSize;
   cout<<"Enter the size of a form . "<<endl;
   cin >>frameSize;
   cout<<endl<<"Enter the frames bits in form of 0 and 1 "<<endl;
   bool bit;
   for(int i=0;i<frameSize;i++){
      cout <<"Enter bit . "<<endl;
      cin>>bit;
      BS.Insertion(bit);
   }
   BS.display();
   BS.bit_stuffing();
   cout<<endl<<"Bit stuffed data is : "<<endl;
   BS.display();
}