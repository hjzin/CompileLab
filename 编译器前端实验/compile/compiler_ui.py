# 编译器界面
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import Qt
import sys


class Ui_Dialog(QtWidgets.QDialog):
    def __init__(self):
        super(Ui_Dialog, self).__init__()
        self.init_ui()

    def init_ui(self):
        #窗体属性
        self.setObjectName("compiler")
        self.resize(379, 497)

        #定义控件
        self.input_line = QtWidgets.QLabel(self)
        self.input_line.setGeometry(QtCore.QRect(30, 70, 111, 16))
        self.input_line.setObjectName("input_line")
        self.title = QtWidgets.QLabel(self)
        self.title.setGeometry(QtCore.QRect(50, 10, 281, 51))
        self.title.setAlignment(Qt.AlignCenter)
        font = QtGui.QFont()
        font.setFamily("STHeiti")
        font.setPointSize(21)
        font.setBold(True)
        font.setWeight(75)
        self.title.setFont(font)
        self.title.setObjectName("title")
        self.input_text = QtWidgets.QLineEdit(self)
        self.input_text.setGeometry(QtCore.QRect(30, 100, 251, 71))
        self.input_text.setObjectName("input")
        self.output_line = QtWidgets.QLabel(self)
        self.output_line.setGeometry(QtCore.QRect(30, 240, 131, 41))
        self.output_line.setObjectName("output_line")
        self.analyse = QtWidgets.QPushButton(self)
        self.analyse.setGeometry(QtCore.QRect(100, 190, 113, 32))
        self.analyse.setObjectName("analyse")
        self.output = QtWidgets.QTextEdit(self)
        self.output.setGeometry(QtCore.QRect(30, 290, 251, 71))
        self.output.setObjectName("output")
        self.error_line = QtWidgets.QLabel(self)
        self.error_line.setGeometry(QtCore.QRect(30, 370, 60, 16))
        self.error_line.setObjectName("error_text")
        self.error_text = QtWidgets.QLineEdit(self)
        self.error_text.setGeometry(QtCore.QRect(30, 400, 251, 71))
        self.error_text.setObjectName("error_line")

        self.setWindowTitle("编译器系统")
        self.title.setText("简易编译器中间代码生成系统")
        self.input_line.setText("请输入赋值语句")
        self.analyse.setText("分析")
        self.output_line.setText("生成的四元式序列")
        self.error_line.setText("错误信息")


if __name__ == '__main__':
    app = QtWidgets.QApplication(sys.argv)
    ui = Ui_Dialog()
    ui.show()
    sys.exit(app.exec_())
