#include"Heap.hpp"


void Heapfy(Vector &Heapp)
{

  Itens item;
  Vector AUX;

  for(auto component : Heapp.vet)
  {
    item = component;
    AUX.vet.push_back(item);
  }

  Heapp.vet.clear();

  for(auto k: AUX.vet)
  {
      item = k;
      Heapp.vet.push_back(item);

         if(Heapp.vet.size() - 1 != 0)                                                     
         {                                                          
           int i = Heapp.vet.size() - 1;                                                     
           int aux = (i - 1) / 2;                                                     
                                                       
           while(Heapp.vet[i].frequence < Heapp.vet[aux].frequence)                               
             {                                                              
                std::swap(Heapp.vet[i],Heapp.vet[aux]);                                 
                i = aux;                                                                           
    
                aux = (i - 1)/2;                              
             }
         }      
  }
  
  return;
   
}


void FillingHeap(Vector &Heapp,Hashh &mp,wstring wstr){

  int counter = 0;
  Itens item;
  
  for(auto element : mp.mp)                                                     
        { 
          if(counter < 20){
            item.frequence = element.second.appearences;
            item.value = element.first;               

            if(element.first != wstr)
            {
              Heapp.vet.push_back(item);                                                     
            }

            if(counter == (20 - 1)){
            
              Heapfy(Heapp);
            }
            counter++;            
        }else{
          if(element.second.appearences > Heapp.vet[0].frequence && (element.first != wstr))
          {
            Heapp.vet[0].value = element.first;
            Heapp.vet[0].frequence = element.second.appearences;
            Heapfy(Heapp);
          }
        }
        }  
}
//end code
