CREATE TABLE student
(
  roll_no INT PRIMARY KEY,
  name VARCHAR(20) NOT NULL,
  gender CHAR(6) NOT NULL,
  mark INT CHECK(mark<=100)
);

SELECT * FROM student;

INSERT INTO student VALUES(101,'Achu','Male',100);
INSERT INTO student VALUES(102,'Appu','Male',96);
INSERT INTO student VALUES(103,'Aishu','Female',100);
INSERT INTO student VALUES(104,'Chottu','Male',80);
INSERT INTO student VALUES(105,'Ammu','Female',65);

SELECT name FROM student WHERE gender = 'Male';

SELECT AVG(mark) FROM student;

SELECT roll_no, name, mark FROM student WHERE mark=(SELECT MAx(mark) FROM student);

ALTER TABLE student ADD COLUMN place VARCHAR(20);

UPDATE student SET place = 'Kannur' WHERE roll_no = 101;
UPDATE student SET place = 'Kasargod' WHERE roll_no = 102;
UPDATE student SET place = 'Wayanad' WHERE roll_no = 103;
UPDATE student SET place = 'Kollam' WHERE roll_no = 104;
UPDATE student SET place = 'Idukki' WHERE roll_no = 105;

SELECT name, place FROM student WHERE gender = 'Female' AND mark BETWEEN 35 AND 70;
