#### 1. Найти все товары покупка которых расписана на более чем 3 чека (вроде такое условие)
```
SELECT s.ProductID FROM Sales.SalesOrderDetail as s
GROUP BY s.ProductID
HAVING COUNT(*) > 3
```
#### 2. Найти все цвета товаров, такие что, товаров этого цвета не менее 2 и не более 5 в данном магазине.
```
SELECT p.Color FROM Production.Product as p
GROUP BY p.Color
HAVING COUNT(*) >= 2 AND COUNT(*) <= 5
```
#### 3. Найти номера подкатегорий товаров, таких что существует не менее двух товаров с цветом Red в этой подкатегории
```
SELECT p.ProductSubcategoryID FROM Production.Product as p
WHERE p.ProductSubcategoryID is not null AND p.Color = 'Red'
GROUP BY p.ProductSubcategoryID
HAVING Count(p.Color) >= 2
```
#### 4. Найти товары, которые были куплены более трех раз, при этом цена товара была более 100
```
SELECT s.ProductID FROM Sales.SalesOrderDetail as s
WHERE s.UnitPrice > 100
GROUP BY s.ProductID
HAVING Count(*) > 3
```
#### 5. Вывести на экран список размерова, товаров отсортированный по убыванию количества красных товаров этого размера.
```
SELECT P.Size FROM Production.Product as p
WHERE p.Color = 'Red' AND p.size is not null
GROUP BY p.Size
ORDER BY p.Size desc
```
#### 6. Найти все размеры товаров, таких что товаров этого размера более 10.
```
SELECT P.Size FROM Production.Product as p
WHERE p.Size is not null
GROUP BY p.Size
HAVING COUNT(*) > 10
```
#### 7. Найти самый продаваемый товар, его ProductId, из числа тех чья цена продажи, UnitPrice, не превышает 100
```
SELECT TOP 1 s.ProductID FROM Sales.SalesOrderDetail as s
WHERE s.UnitPrice <= 100
GROUP BY S.ProductID
ORDER BY COUNT(*) DESC
```
#### 8. Найти номер подкатегории товаров с наибольшим разнообразицем цветов в ней
```
SELECT top 1 p.ProductSubcategoryID
FROM Production.Product as p
WHERE p.Color is not NULL and p.ProductSubcategoryID is not NULL
GROUP BY p.ProductSubcategoryID
ORDER BY COUNT(distinct p.color) desc
```
#### 9. Найти список товаров ProductId которые продовались на один чек в кол-ве (OrderQty) менее 3шт за раз при этом были куплены более чем в 3разных чеков
```
select p.ProductID
from Sales.SalesOrderDetail as p
where p.OrderQty < 3
group by p.ProductID
having COUNT(*) > 3 
```
#### 10. Вывести на экран ProductID категорий с наибольшим кол-вом подкатегорий
```
SELECT p.ProductCategoryID
From Production.ProductSubcategory as p
GROUP by p.ProductCategoryID
ORDER BY COUNT(*) DESC
```
#### 11. Вывести номера подкатегорий, на которые приходится более 5 товаров
```
select p.ProductSubcategoryID
from Production.Product as p
where p.ProductSubcategoryID is not null
group by p.ProductSubcategoryID
having COUNT(*) > 5
```
#### 12. Вывести номера подкатегории на которые приходится более 5 товаров red
```
select p.ProductSubcategoryID
from Production.Product as p
where p.ProductSubcategoryID is not null and p.Color = 'Red'
group by p.ProductSubcategoryID
having COUNT(*) > 5
```
