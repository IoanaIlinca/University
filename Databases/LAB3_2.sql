use CoffeeShop
go

INSERT INTO CoffeeTypes(Pid, Name, Origin, Quantity) VALUES (1, 'Arabica', 'Africa', 10)
INSERT INTO CoffeeTypes(Pid, Name, Origin, Quantity) VALUES (2, 'Robusta', 'South America', 12)

select * from CoffeeTypes

SET IDENTITY_INSERT MilkTypes ON
INSERT INTO MilkTypes(Mid, Name, Type, Vegan) VALUES (1, 'Monor', 'Cow', 0)

select * from MilkTypes

INSERT INTO CoffeeCups(Pid, Mid, Name, Type, Price) VALUES (1, 1, 'Espresso', 'Tall', 12)

select * from CoffeeCups

UPDATE CoffeeCups
SET Price=14

select * from CoffeeCups

DELETE FROM CoffeeTypes
WHERE Name Like 'Robusta'

select * from CoffeeTypes