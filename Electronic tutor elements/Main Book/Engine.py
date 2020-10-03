from PyQt5 import QtWidgets, QtCore, QtGui

# Импортируем MainBook.py, из него - основной класс
from MainBook import Ui_mainWindow

#Импортируем содержимое окон Dialog (About), Manual
from dialogs.About import Ui_Dialog
from dialogs.Manual import Ui_Manual

import sys

#ОСНОВНОЕ ОКНО УЧЕБНИКА (далее - содержимое)
class mywindow(QtWidgets.QMainWindow):
    def __init__(self):
        super(mywindow, self).__init__()
        self.ui = Ui_mainWindow()
        self.ui.setupUi(self)
        
#Тестовая программа
class test (QtWidgets.QDialog):
    def __init__(self, parent=None):
        super(test, self).__init__(parent)
        self.ui = testWindow()
        self.ui.setupUi(self)

#Окно "Об этом учебнике"
class aboutDialog (QtWidgets.QDialog):
    def __init__(self, parent=None):
        super(aboutDialog, self).__init__(parent)
        self.ui = Ui_Dialog()
        self.ui.setupUi(self)

#Окно "Руководство пользователя"
class manualDialog (QtWidgets.QDialog):
    def __init__(self, parent=None):
        super(manualDialog, self).__init__(parent)
        self.ui = Ui_Manual()
        self.ui.setupUi(self)



#Пачка кнопок
        self.ui.pushButton.clicked.connect (self.about) #"Об этом учебнике"
        self.ui.pushButton_2.clicked.connect (self.manual) #"Руководство пользователя"
        self.ui.pushButton_3.clicked.connect (self.test) #"Начать тест"

#Функции кнопок
    def about (self): #"Об этом учебнике"
            dialog = aboutDialog(self)
            dialog.exec_()
            
    def manual (self): #"Руководство пользователя"
            dialog = manualDialog(self)
            dialog.exec_()

    def test (self): #Тестовая программа
            dialog = test(self)
            dialog.exec_()





app = QtWidgets.QApplication([])
application = mywindow()
application.show()

sys.exit(app.exec())
