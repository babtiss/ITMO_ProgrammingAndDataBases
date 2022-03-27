#### 1. Найти и вывести на экран названия продуктов, для которых определён цвет, но не определён размер
```
SELECT p.name, p.Color
FROM Production.Product as p
WHERE p.Color IS NOT NULL and p.Size is NULL
```
#### 2. Найти и вывести название продуктов, у которых номер подкатегории равен 1 или 3.
```
SELECT p.name
FROM Production.Product as p
WHERE p.ProductSubcategoryID = 1 OR p.ProductSubcategoryID = 3
```
#### 3. Найти и вывести на экран название продуктов, у которых цена лежит в диапазоне от 40 до 300 не включая границы диапазона.
```
SELECT p.name
FROM Production.Product as p
WHERE p.StandardCost > 40 and p.StandardCost < 300
```
#### 4. Найти и вывести на экран названия продуктов, у которых цена меньше 40 или больше 300
```
SELECT p.name
FROM Production.Product as p
WHERE p.StandardCost < 40 or p.StandardCost > 300
```
#### 5. Найти и вывести на экран названия продуктов, у которых цена лежит в диапазоне от 40 до 300 включая границы.
```
SELECT p.name
FROM Production.Product as p
WHERE p.StandardCost >= 40 and p.StandardCost <= 300
```
#### 6. Найти и вывести на экран названия подкатегорий с номерами 1, 3, 5.
```
SELECT p.Name
FROM Production.ProductSubcategory as p
WHERE p.ProductSubcategoryID in (1,3,5)
```
#### 7. Найти и вывести на экран названия категорий с номерами 1, 3, 7.
```
SELECT p.Name
FROM Production.ProductCategory as p
WHERE p.ProductCategoryID in (1,3,7)
```
#### 8. Найти и вывести на экран имя клиентов(Person таблица) у которых среднее им MiddleName состоит более чем из 1 буквы
```
SELECT p.FirstName
FROM Person.Person as p
WHERE p.MiddleName like '__%'
```
#### 9. Найти и вывести на экран нахвание продуктов, у которых третья буква названия или 'u' или 'а'
```
SELECT p.Name
FROM Production.Product as p
WHERE p.Name like '__u%' or p.Name like '__a%'
```
или 
```
SELECT p.Name
FROM Production.Product as p
WHERE p.Name like '__[ua]%'
```

#### 10. Найти и вывести на экран название продуктов, у которых в названии нет букв a,d,g,k,f,t,r
```
SELECT p.Name
FROM Production.Product as p
WHERE p.Name not like '%[adgkftr]%'
```
#### 11. Найти и вывести на экран название продуктов, у которых ProductNumber содержив в себе дефис
```
SELECT p.Name
FROM Production.Product as p
WHERE p.Name like '%-%'
```
