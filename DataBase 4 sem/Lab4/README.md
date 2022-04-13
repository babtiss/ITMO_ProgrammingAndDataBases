### 1. Найти название и айдишники продуктов, у которых цвет совпадает с такими товарами цена на которые была меньше 5000
```
SELECT Name, ProductID
FROM Production.product
WHERE Color in
(SELECT Color FROM Production.product WHERE ListPrice < 5000)
```
### 2. Вывести на экран товары и ид у которых цвет совпадает с цветом самого дорогого товара.
```
SELECT Name, ProductID
From Production.Product
Where Color in
(SELECT Color From Production.Product
Where ListPrice = (SELECT MAX(ListPrice) From Production.Product))
```
### 3. Вывести названия товаров, чей цвет совпадает с цветом одного из товаров,
чья цена меньше 4000
```
SELECT Name
FROM Production.Product
WHERE Color in
(SELECT Color
FROM Production.Product WHERE ListPrice < 4000)
```
### 4. Найти название подкатегории где содержится самый дорогой товар с
красным цветом

```
SELECT psc.Name 
FROM Production.ProductSubcategory as psc
WHERE psc.ProductSubcategoryID IN (
    SELECT top 1 p.ProductSubcategoryID 
    FROM Production.Product as p
    WHERE p.Color = 'red'
    ORDER BY p.ListPrice desc
)
```

### 5. Найти название категории с наибольшим количеством товаров 
```
SELECT pc.Name
FROM Production.ProductCategory as pc
WHERE pc.ProductCategoryID =
(SELECT top 1 psc.ProductCategoryID
FROM Production.Product as p
JOIN Production.ProductSubcategory as psc 
ON p.ProductSubcategoryID = psc.ProductSubcategoryID
GROUP BY psc.ProductCategoryID
ORDER BY count(ProductID) desc)
```

### 6. Название товаров, чей цвет совпадает с товаром, чья цена больше 2000
```
SELECT p.Name
FROM Production.Product as p
WHERE p.Color in
(Select p.Color
FROM Production.Product as p
WHERE p.ListPrice > 2000
)
```

### 7. Найти номер покупателя и самый дорогой купленный им товар для
каждого покупателя
```
SELECT soh.CustomerID, (SELECT MAX(SOD.UnitPrice)
FROM Sales.SalesOrderDetail AS sod
WHERE sod.SalesOrderID = soh.SalesOrderID) AS MaxPrice
FROM Sales.SalesOrderHeader AS soh
```

### 8.Самый дорогой товар красного цвета в каждой подкатегории
```
SELECT *
FROM Production.Product AS P
WHERE p.Color = 'Red' and p.ListPrice in 
(SELECT MAX(s.ListPrice) 
FROM Production.Product as s 
WHERE s.ProductSubcategoryID = p.ProductSubcategoryID and s.color = 'Red')
```

### 9. Skip

### 10. Найти номера чеков, таких что покупатели, к которым относятся эти чеки,
ходили в магазин более трех раз, т.е. имеют более трех чеков
```
SELECT soh.SalesOrderID
FROM Sales.SalesOrderHeader AS soh
WHERE soh.CustomerID in
(Select s.CustomerID
FROM Sales.SalesOrderHeader as s
GROUP BY s.CustomerID
HAVING COUNT(*) > 3
)
```

### 11. Найти номера категорий товаров, такие что в них товаров с красным цветом
больше, чем с черным.

```
SELECT pc.ProductCategoryID
FROM Production.ProductCategory AS pc
WHERE 
(SELECT Count(p.ProductID)
FROM Production.Product as p
JOIN Production.ProductSubcategory as psc
ON psc.ProductSubcategoryID = p.ProductSubcategoryID
WHERE p.Color = 'Black' and pc.ProductCategoryID = psc.ProductCategoryID
) > 
(SELECT Count(p.ProductID)
FROM Production.Product as p
JOIN Production.ProductSubcategory as psc
ON psc.ProductSubcategoryID = p.ProductSubcategoryID
WHERE p.Color = 'Red' and pc.ProductCategoryID = psc.ProductCategoryID
)
```

### 12. Найти название категории самого продаваемого товара (по количеству чеков на которые он был продан)
```
select pc1.Name from Production.ProductCategory as pc1
where pc1.ProductCategoryID =
(select top 1 pc.ProductCategoryID from Production.ProductCategory as pc
inner join Production.ProductSubcategory as psc
on psc.ProductCategoryID = pc.ProductCategoryID
inner join Production.Product as p
on p.ProductSubcategoryID = psc.ProductSubcategoryID
inner join Sales.SalesOrderDetail as sod
on sod.ProductID = p.ProductID
inner join Sales.SalesOrderHeader as soh
on soh.SalesOrderID = sod.SalesOrderID
group by pc.ProductCategoryID
order by count(soh.SalesOrderID) desc)

или 

select pc.Name
from Production.Product as p
join Production.ProductSubcategory as ps
on ps.ProductSubcategoryID = p.ProductSubcategoryID
join Production.ProductCategory as pc
on pc.ProductCategoryID = ps.ProductCategoryID
where p.ProductID in (
	select top 1 sod.ProductID
	from Sales.SalesOrderDetail as sod
	group by sod.ProductID
	order by count(*) desc
) 
```

### 13. Найти все товары, названия, которые куплены более трех раз, и которые имеют более трех покупателей
```
SELECT p.name
FROM Production.Product as p
WHERE p.ProductID IN 
(
SELECT sod.ProductID
FROM Sales.SalesOrderDetail as sod
JOIN Sales.SalesOrderHeader as soh
ON sod.SalesOrderID = soh.SalesOrderID
GROUP BY sod.ProductID
HAVING COUNT(DISTINCT soh.CustomerID) > 3
)
```

### 14. Найти название подкатегории с наибольшим количеством товаров (с подзапросом)
