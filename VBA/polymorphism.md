Сначала объявим абстрактный класс:
```vba
Public Sub Voice()

End Sub
```
Затем три его реализации:
1. Bird
```vba
Implements Animal

Private Sub Animal_Voice()
    Debug.Print "Tweet-tweet!"
End Sub
```
2. Cat
```vba
Implements Animal

Private Sub Animal_Voice()
    Debug.Print "Meow-meow!"
End Sub
```
3. Dog
```vba
Implements Animal

Private Sub Animal_Voice()
    Debug.Print "Woof-woof!"
End Sub
```
Затем в главном модуле:
```vba
Public Sub main()

    Dim animals(1 To 3) As Animal
    Dim i As Integer

    Set animals(1) = New Dog
    Set animals(2) = New Cat
    Set animals(3) = New Bird

    For i = LBound(animals) To UBound(animals)
        Call animals(i).Voice
    Next
   
End Sub
```
Полученный вывод:
![image](https://sun7-6.userapi.com/H8ohJrQ4LU2dkI3gKQIdrf5Op47oYeseHXO5hA/iHjyNL0rtrc.jpg)
