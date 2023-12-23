#include <iostream>
using namespace std;

////////////////////////////////////////

//Слой абстрактных классов
class product {
private:
    string _name;
    int _price;
    string _manufacturer_country;
    int _in_stock;
protected:
    bool is_product_ended = false;
    string rub_info() 
    {
        if (_price % 10 == 1)
            return " рубль";
        else if(_price % 10==3 || _price % 10 == 2)
            return " рубля";
        else
            return " рублей";
    }
public:
    product() {}
    product(string __name, int __price, string __manufacturer_country, int __in_stock)
    {
        _name = __name;
        _price = __price;
        _manufacturer_country = __manufacturer_country;
        _in_stock = __in_stock;
    }

    string name() { return _name; }
    int price() { return _price; }
    string manufacturer_country() { return _manufacturer_country; }
    int in_stock() { return _in_stock; }

    virtual void sale() 
    {
        if (_in_stock == 0) {
            cout << "товар закончился" << endl;
            is_product_ended = true;
            return;
        }
        else if (_in_stock < 10)
            cout << "товар скоро закончится!" << endl;
        _in_stock--;
    }
    virtual void show_info() {}

};

class dible_product : virtual public product
{
protected:
    int _calories = -1;
public:

    dible_product() {}
    dible_product(int __calories)
    {
        _calories = __calories;
    }
    virtual void sale() {}
    virtual void show_info() {}
    int calories() { return _calories; }
};
class non_dible_product : virtual public product
{
protected:
    string _material;
public:
    non_dible_product() {}
    non_dible_product(string __material) 
    {
        _material = __material;
    }
    string material() { return _material; }
    virtual void sale() {}
    virtual void show_info() {}
};

class toys : virtual public non_dible_product {
protected:
    int _age_restrictions;
    string _color;
public:
    toys() {}
    toys(int __age_restrictions, string __color) 
    {
        _age_restrictions = __age_restrictions;
        _color = __color;
    }
    int age_restrictions() { return _age_restrictions; }
    string color() { return _color; }
    virtual void sale() {}
    virtual void show_info() {}
};

/// ///////////////////////////////////////


/// <Производные классы>
/// /////////////////
/// </summary>
class cake : public dible_product{
private:
    int _count_layers = -1;
public:
    cake(string __name, int __price, string __manufacturer_country, int __in_stock)
        :product(__name, __price, __manufacturer_country, __in_stock) {}
    cake(string __name, int __price, string __manufacturer_country, int __calories, int __count_layers, int __in_stock)
        :product(__name, __price, __manufacturer_country, __in_stock)
        ,dible_product(__calories)
    {
        _count_layers = __count_layers;
    }
    int count_layers() { return _count_layers; }
    void sale() 
    {
        product::sale();
        if(!is_product_ended)
            cout << "The cake was sold" << endl << endl;
    }
    void show_info()
    {
        cout << "Название товара - " << name() << endl
            << "Цена - " << price() << rub_info() << endl
            << "Осталось на складе - " << in_stock() << endl
            << "Страна производитель - " << manufacturer_country() << endl
            << "Калории  - " << calories() << " ККал" << endl
            << "Количество слоёв - " << count_layers() << endl << endl;
    }
};

class candies : public dible_product {
private:
    string _filling;
public:
    candies(string __name, int __price, string __manufacturer_country, int __in_stock) 
        :product(__name, __price, __manufacturer_country, __in_stock) {}
    candies(string __name, int __price, string __manufacturer_country, int __calories, string __filling, int __in_stock)
        : product(__name, __price, __manufacturer_country, __in_stock)
        ,dible_product(__calories) {
        _filling = __filling;
    }
    string filling() { return _filling; }
    void sale() 
    {
        product::sale();
        if (!is_product_ended)
            cout << "The candies was sold" << endl << endl;
    }

    void show_info()
    {
        cout << "Название товара - " << name() << endl
            << "Цена - " << price()<< rub_info() << endl
            << "Осталось на складе - " << in_stock() << endl
            << "Страна производитель - " << manufacturer_country() << endl
            << "Калории  - " << calories() <<" ККал" << endl
            << "Начинка - " << filling() << endl << endl;
    }
};


class cars: public toys {
private:
    string _car_model;
public:
    cars(string __name, int __price, string __manufacturer_country, int __in_stock)
        :product(__name, __price, __manufacturer_country, __in_stock) {}
    cars(string __name, int __price, string __color, string __manufacturer_country, string __material, int __age_restrictions, string __car_model, int __in_stock)
        :product(__name, __price, __manufacturer_country, __in_stock), non_dible_product(__material), toys(__age_restrictions,__color){
        _car_model = __car_model;
    }
    string car_model() { return _car_model; }
    void sale() 
    {
        product::sale(); 
        if (!is_product_ended)
            cout << "The toy car was sold" << endl << endl;
    }
    void show_info()
    {
        cout << "Название товара - " << name() << endl
            << "Цена - " << price() << rub_info() << endl
            << "Осталось на складе - " << in_stock() << endl
            << "Страна производитель - " << manufacturer_country() << endl
            << "Цвет - " << color() << endl
            << "Материал - " << material() << endl
            << "Возрастные ограничения - " << age_restrictions() <<"+" << endl
            << "Модель машинки  - " << car_model() << endl << endl;
    }
};
class rabbit : public toys {
    
public:
    rabbit(string __name, int __price, string __manufacturer_country, int __in_stock)
        :product(__name, __price, __manufacturer_country, __in_stock) {}
    rabbit(string __name, int __price, string __color, string __manufacturer_country, string __material, int __age_restrictions, int __in_stock)
        :product(__name, __price, __manufacturer_country, __in_stock), non_dible_product(__material), toys(__age_restrictions, __color) {}
    void sale() 
    {
        product::sale();
        if (!is_product_ended)
            cout << "The toy rabbit was sold" << endl << endl;
    }
    void show_info()
    {
        cout << "Название товара - " << name() << endl
            << "Цена - " << price() << rub_info() << endl
            << "Осталось на складе - " << in_stock() << endl
            << "Страна производитель - " << manufacturer_country() << endl
            << "Цвет - " << color() << endl
            << "Материал - " << material() << endl
            << "Возрастные ограничения - " << age_restrictions() << "+" << endl<<endl;
    }
};

int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    product* p;
    candies can = candies("Батончик", 2, "Россия", 70, "клубника", 2);
    p = &can;
    p->show_info();
    p->sale();
    p->sale();
    
    p->sale();
    cout << endl;

    cars car = cars("Игрушечная модель Audi 1960 года!",1000,"Чёрный","Германия","Дерево",12,"Audi F103", 5);
    p = &car;
    p->show_info();
    p->sale();

    cake _cake = cake("Торт вкусный", 50, "Россия", 500,3, 10000);
    p = &_cake;
    p->show_info();
    p->sale();

    rabbit rab = rabbit("Зайчик новогодний", 20, "Белый", "Китай", "шерсть", 3, 50);
    p = &rab;
    p->show_info();
    p->sale();
}