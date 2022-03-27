
1. Вывести названия категорий товаров, количество продуктов в которых больше 20
```
SELECT PC.Name, count(*) AS _count
FROM Production.Product AS P
INNER JOIN Production.ProductSubcategory AS PSC
ON P.ProductSubcategoryID=PSC.ProductSubcategoryID		
INNER JOIN Production.ProductCategory AS PC
ON PSC.ProductCategoryID=PC.ProductCategoryID 
GROUP BY PC.Name 
HAVING count(*)>20
```
2. Получить названия первых двух категорий товаров из упорядоченного по возрастанию  количества товаров в категории списка
```
SELECT top 2 PC.Name
FROM Production.ProductCategory as PC
JOIN Production.ProductSubcategory as PSC
ON psc.ProductCategoryID = pc.ProductCategoryID
JOIN Production.Product as P
ON psc.ProductSubcategoryID = p.ProductSubcategoryID
GROUP BY pc.ProductCategoryID, pc.Name
ORDER BY count(*) asc
 ```
3. Найти названия товаров, которые были проданы хотя бы один раз
```
SELECT p.Name
FROM Production.Product as p
JOIN Sales.SalesOrderDetail as sod
ON p.ProductID = sod.ProductID
GROUP BY p.Name
```
4. Найти названия товаров, которые не были проданы ни разу 
```
SELECT p.name 
FROM Production.Product as p
LEFT JOIN Sales.SalesOrderDetail as sod 
ON p.ProductID=sod.ProductID
WHERE sod.ProductID is NULL
GROUP BY p.name
```

5. Вывести на экран список товаров, названия, упорядоченный по количеству продаж, по возрастанию
```
SELECT p.name, count(*) as _count
FROM Production.Product as p
JOIN Sales.SalesOrderDetail as sod 
ON p.ProductID=sod.ProductID
GROUP BY p.ProductID, p.name
ORDER BY count(*)
```

6. Вывести на экран первых три товара с наибольшим количеством продаж
```
SELECT top 3 p.name
FROM Production.Product as p
JOIN Sales.SalesOrderDetail as sod 
ON p.ProductID=sod.ProductID
GROUP BY p.ProductID, p.name
ORDER BY count(*) desc
```

7. Вывести на экран список категорий, названия, упорядоченный по количеству продаж товаров этих категорий, по возрастанию
```
SELECT pc.ProductCategoryID, pc.Name , COUNT(sod.OrderQty) as _count_sale
FROM Sales.SalesOrderDetail as sod
JOIN Production.Product as p
ON sod.ProductID = p.ProductID
JOIN Production.ProductSubcategory as psc
ON p.ProductSubcategoryID = psc.ProductSubcategoryID
JOIN Production.ProductCategory as pc
ON psc.ProductCategoryID = pc.ProductCategoryID
GROUP BY pc.ProductCategoryID, pc.Name
ORDER BY COUNT(sod.OrderQty)
```

8. Вывести список поставщиков, названия вендоров, упорядоченный по количеству поставляемых товаров, по возрастанию (Повыш принял)
```
SELECT v.Name
FROM Purchasing.Vendor as v
JOIN Purchasing.ProductVendor as pv
ON pv.BusinessEntityID = v.BusinessEntityID
JOIN Production.Product as p
ON p.ProductID = pv.ProductID
GROUP BY v.Name
ORDER BY COUNT(*) ASC
```
9. Получить названия первых двух категорий товаров из упорядоченного по возрастанию количества товаров в категории списка n
```
SELECT top 2 pc.Name
FROM Production.Product as p
JOIN Production.ProductSubcategory as psc
ON psc.ProductSubcategoryID = p.ProductSubcategoryID
JOIN Production.ProductCategory as pc
ON psc.ProductCategoryID = pc.ProductCategoryID
GROUP BY pc.Name
ORDER BY COUNT(*) ASC
```
 
10. Найти сколько различных размеров товаров приходится на каждую категорию товаров
```
SELECT pc.Name, count(distinct p.Size)
FROM Production.Product as p
JOIN Production.ProductSubcategory as psc
ON psc.ProductSubcategoryID = p.ProductSubcategoryID
JOIN Production.ProductCategory as pc
ON psc.ProductCategoryID = pc.ProductCategoryID
WHERE p.Size is not Null
GROUP BY pc.Name
 ```
10(a). Найти название товаров, которые были куплены или три, или пять раз
```
SELECT p.Name
FROM Production.Product as p
JOIN Sales.SalesOrderDetail as sod
ON p.ProductID = sod.ProductID
GROUP BY p.Name
HAVING COUNT(*)=3 OR COUNT(*)=5
```
11. Подкатегории, которые больше 5…. 
```
SELECT psc.Name, count(*) AS _count
FROM Production.Product p
JOIN Production.ProductSubcategory psc
ON p.ProductSubcategoryID = psc.ProductSubcategoryID
GROUP BY psc.Name
HAVING count(*) > 5
```
12. Найти названия тех категорий товаров, где количество товаров более 20
```
SELECT pc.Name, count(*)
FROM Production.Product as p
JOIN Production.ProductSubcategory as psc
ON p.ProductSubcategoryID = psc.ProductSubcategoryID
JOIN Production.ProductCategory as pc
ON pc.ProductCategoryID = psc.ProductCategoryID
GROUP BY pc.Name
HAVING Count(*) > 20
```
13. Найти название товаров синего цвета, купленных ровно два раза, и вывести категории к которым относится товар.
```
SELECT p.Name, pc.Name
FROM Production.Product AS p
JOIN Production.ProductSubcategory AS psc
ON p.ProductSubcategoryID = psc.ProductSubcategoryID
JOIN Production.ProductCategory AS pc
ON pc.ProductCategoryID = psc.ProductCategoryID
JOIN Sales.SalesOrderDetail AS sod
ON p.ProductID = sod.ProductID
WHERE p.Color = 'Blue'
GROUP BY p.Name, pc.Name
HAVING COUNT(sod.ProductID) = 2
```
