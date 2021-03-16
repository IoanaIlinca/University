use CoffeeShop
go

Select * From CoffeeCups
INSERT INTO CoffeeTypes(Pid, Name, Origin, Quantity) VALUES (2, 'Robusta', 'South America', 12)
Select * From CoffeeCups


SET IDENTITY_INSERT MilkTypes ON
INSERT INTO MilkTypes(Mid, Name, Type, Vegan) VALUES (3, 'Kaufland', 'Almond', 1)
Select * From MilkTypes
Select * From MilkTypes 
WHERE Vegan = 1

SET IDENTITY_INSERT MilkTypes ON
INSERT INTO MilkTypes(Mid, Name, Type, Vegan) VALUES (1, 'Napolact', 'Cow', 0)
Select * From MilkTypes