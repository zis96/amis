#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// структура їжа 
struct eat_on_canteen{
	enum type_eat{
		hot_eat,  //0
		cold_eat, //1
		dessert   //2
	};
	enum type_eat type_eat; //тип їжі
	char *name_eat;          //назва їжі
	int amount_of_portions; // кількість порцій
	float expense;          // ціна 
}eat;
// функція створення структури eat_on_canteen
struct eat_on_canteen *my_food =NULL;

struct eat_on_canteen *createEat(){
	my_food=(struct eat_on_canteen *)malloc(sizeof( struct eat_on_canteen)); 
 /*// для перевірки :
	int a; 
	char *b = (char *)malloc(sizeof(char) * 80); 
	scanf("%d",&a);
	fflush(stdin);
	gets(b);
	my_food->amount_of_portions=a;
	my_food->name_eat=b;
	my_food->type_eat = hot_eat;
//*/
	
	return my_food;
}
// функція очистки памяті виділену під структуру eat_on_canteen
struct eat_on_canteen *deleteEat(){
	free(my_food);
	return 0;
}

// структура замовник 
struct customer{
	enum status_of_the_person{
		enterprise, // юридична особа
    	individual  // фізична особа
    };
	char name; //ім'я замовника 
	int year;  // вік замовника 
	enum status_of_the_person status; // статус
}customer;

// функція створення структури customer
struct customer *point_customer =NULL;

struct customer *createCustomer(){
	point_customer=(struct customer *)malloc(sizeof( struct customer)); 
	
	return point_customer;
}
// функція очистки памяті виділену під структуру customer
struct customer *deleteCustomer(){
	free(point_customer);
	return 0;
}
// структура купівля 

struct purchase {
	enum view_order { // вид замовлення 
		electron,    // електронно
		personally   // особисто
	};
	enum payment_method{
		cash, // готівка
		card  // картка
	};
	enum view_order view;  // вид замовлення 
	char name_dish ;        // назва страви
	enum payment_method method ; //спосіб оплати 
	float expense;             // ціна 
	
}purchase ;
// функція створення структури purchase
struct purchase *point_purchase =NULL;

struct purchase *createPurchase(){
	point_purchase=(struct purchase *)malloc(sizeof( struct purchase)); 
	
	return point_purchase;
}
// функція очистки памяті виділену під структуру customer
struct purchase *deletePurchase(){
	free(point_purchase);
	return 0;
}

int main(int argc, char *argv[]) {
	
/* //для перевірки :
	my_food= createEat();
	printf("%d", my_food->amount_of_portions);
	printf("%s\n", my_food->name_eat);
	my_food=deleteEat;  */

	return 0;
}
