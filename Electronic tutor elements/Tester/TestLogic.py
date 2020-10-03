from PyQt5 import QtWidgets
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QMessageBox

# Импортируем MainBook.py, из него - основной класс
from tests.Test3 import Ui_Dialog

import sys



#Основной класс окна
class testWindow(QtWidgets.QDialog):

#Переменная счетчика правильных ответов
    def __init__(self):
        super(testWindow, self).__init__()
        self.ui = Ui_Dialog()
        self.ui.setupUi(self)
#Событие: нажата кнопка pushButton ("Проверить") - вызов метода проверки результатов
        self.ui.pushButton.clicked.connect (self.checkResults)

    def checkResults (self):    #Метод проверки результатов
        global counter
        counter = 0
    #Пачка условий на правильные и неправильные ответы на каждый вопрос
    #Вопрос 1:
        if self.ui.ButtonT.isChecked():
            counter = counter + 1
        elif self.ui.ButtonF1.isChecked() or self.ui.ButtonF2.isChecked() or self.ui.radioButton_4.isChecked():
            counter = counter

    #Вопрос 2:
        if self.ui.ButtonT_2.isChecked():
            counter = counter + 1
        elif self.ui.ButtonF1_2.isChecked() or self.ui.ButtonF2_2.isChecked() or self.ui.radioButton_5.isChecked():
            counter = counter

    #Вопрос 3:
        if self.ui.ButtonT_3.isChecked():
            counter = counter + 1
        elif self.ui.ButtonF1_3.isChecked() or self.ui.ButtonF2_3.isChecked() or self.ui.radioButton_6.isChecked():
            counter = counter

    #Вопрос 4:
        if self.ui.ButtonT_4.isChecked():
            counter = counter + 1
        elif self.ui.ButtonF1_4.isChecked() or self.ui.ButtonF2_4.isChecked() or self.ui.radioButton_7.isChecked():
            counter = counter

    #Вопрос 5:
        if self.ui.ButtonT_5.isChecked():
            counter = counter + 1
        elif self.ui.ButtonF1_5.isChecked() or self.ui.ButtonF2_5.isChecked() or self.ui.radioButton_8.isChecked():
            counter = counter

    #Вопрос 6:
        if self.ui.ButtonT_6.isChecked():
            counter = counter + 1
        elif self.ui.ButtonF1_6.isChecked() or self.ui.ButtonF2_6.isChecked() or self.ui.radioButton_9.isChecked():
            counter = counter

    #Вопрос 7:
        if self.ui.ButtonT_7.isChecked():
            counter = counter + 1
        elif self.ui.ButtonF1_7.isChecked() or self.ui.ButtonF2_7.isChecked() or self.ui.radioButton_10.isChecked():
            counter = counter
    #Вопрос 8:
        if self.ui.ButtonT_8.isChecked():
            counter = counter + 1
        elif self.ui.ButtonF1_8.isChecked() or self.ui.ButtonF2_8.isChecked() or self.ui.radioButton_11.isChecked():
            counter = counter

    #Вопрос 9:
        if self.ui.ButtonT_9.isChecked():
            counter = counter + 1
        elif self.ui.ButtonF1_9.isChecked() or self.ui.ButtonF2_9.isChecked() or self.ui.radioButton_12.isChecked():
            counter = counter

    #Вопрос 10:
        if self.ui.ButtonT_10.isChecked():
            counter = counter + 1
        elif self.ui.ButtonF1_10.isChecked() or self.ui.ButtonF2_10.isChecked() or self.ui.radioButton_13.isChecked():
            counter = counter

    #Вывод результата:
        buttonReply = QMessageBox.question(self, 'Результаты', "Правильных ответов: " + str(counter), QMessageBox.Ok)

        self.show()




app = QtWidgets.QApplication([])
application = testWindow()
application.show()

sys.exit(app.exec())
