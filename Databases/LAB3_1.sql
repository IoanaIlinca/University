use CoffeeShop
go


CREATE TABLE CoffeeCups
(
Pid INT FOREIGN KEY REFERENCES CoffeeTypes(Pid),
Mid INT FOREIGN KEY REFERENCES MilkTypes(Mid),
CONSTRAINT pk_CoffeeCups PRIMARY KEY (Pid, Mid),
Name varchar(50),
Type varchar(50),
Price INT
)
