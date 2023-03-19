#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "../funtrans/funtrans.hpp"
#include <QDesktopServices>
#include <QMessageBox>
#include <QRegularExpressionValidator>

/**
 * Constructs a new `MainWindow` object.
 *
 * This constructor creates a new `MainWindow` object with the specified
 * parent widget, and initializes
 * a new `Ui::MainWindow` object to handle the user interface elements.
 * The `ui` object contains a
 * hierarchy of widgets and layouts that define the main window and its
 * contents.
 *
 * @param parent A pointer to the parent widget of this `MainWindow`, or
 * `nullptr` if this window
 * has no parent.
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
    connect(ui->buttonHelp, &QPushButton::clicked,
            this, &MainWindow::onButtonHelpClicked);

    connect(ui->buttonClear, &QPushButton::clicked,
            this, &MainWindow::onButtonClearClicked);

    connect(ui->buttonDivi, &QPushButton::clicked,
            this, &MainWindow::onButtonDiviClicked);

    connect(ui->buttonExp, &QPushButton::clicked,
            this, &MainWindow::onButtonExpClicked);

    connect(ui->buttonSin, &QPushButton::clicked,
            this, &MainWindow::onButtonSinClicked);

    connect(ui->buttonCos, &QPushButton::clicked,
            this, &MainWindow::onButtonCosClicked);

    connect(ui->buttonTan, &QPushButton::clicked,
            this, &MainWindow::onButtonTanClicked);

    connect(ui->buttonLn, &QPushButton::clicked,
            this, &MainWindow::onButtonLnClicked);

    connect(ui->buttonLogy, &QPushButton::clicked,
            this, &MainWindow::onButtonLogyClicked);

    connect(ui->buttonPower, &QPushButton::clicked,
            this, &MainWindow::onButtonPowerClicked);

    connect(ui->buttonSinh, &QPushButton::clicked,
            this, &MainWindow::onButtonSinhClicked);

    connect(ui->buttonCosh, &QPushButton::clicked,
            this, &MainWindow::onButtonCoshClicked);

    connect(ui->buttonSqrt, &QPushButton::clicked,
            this, &MainWindow::onButtonSqrtClicked);

    connect(ui->buttonTanh, &QPushButton::clicked,
            this, &MainWindow::onButtonTanhClicked);

    connect(ui->buttonRoot, &QPushButton::clicked,
            this, &MainWindow::onButtonRootClicked);

    connect(ui->buttonAsin, &QPushButton::clicked,
            this, &MainWindow::onButtonAsinClicked);

    connect(ui->buttonAtan, &QPushButton::clicked,
            this, &MainWindow::onButtonAtanClicked);

    connect(ui->buttonCsc, &QPushButton::clicked,
            this, &MainWindow::onButtonCscClicked);

    connect(ui->buttonSec, &QPushButton::clicked,
            this, &MainWindow::onButtonSecClicked);

    connect(ui->buttonCot, &QPushButton::clicked,
            this, &MainWindow::onButtonCotClicked);

    connect(ui->buttonFactorial, &QPushButton::clicked,
            this, &MainWindow::onButtonFactorialClicked);

    connect(ui->buttonPI, &QPushButton::clicked,
            this, &MainWindow::onButtonPIClicked);

    connect(ui->buttonAcos, &QPushButton::clicked,
            this, &MainWindow::onButtonAcosClicked);

    connect(ui->buttonLog10, &QPushButton::clicked,
            this, &MainWindow::onButtonLog10Clicked);

    connect(ui->buttonXSign, &QPushButton::clicked,
            this, &MainWindow::onButtonXSignClicked);

    connect(ui->buttonYSign, &QPushButton::clicked,
            this, &MainWindow::onButtonYSignClicked);

    auto *validator =
    new QRegularExpressionValidator(QRegularExpression(
                        "^[0-9]{0,50}(\\.[0-9]{0,50})?$"), this);
    ui->lineEditX->setValidator(validator);
    ui->lineEditY->setValidator(validator);

    connect(ui->lineEditX, &QLineEdit::textChanged,
            this, &MainWindow::onLineEditXTextChanged);

    connect(ui->lineEditY, &QLineEdit::textChanged,
            this, &MainWindow::onLineEditYTextChanged);

}

/**
 * Destroys the `MainWindow` object.
 *
 * This destructor frees the memory allocated for the `ui` object, which
 * was created in the constructor
 * to handle the user interface elements of the main window. The `delete`
 * operator is used to free the
 * memory, ensuring that any resources held by the object are properly
 * cleaned up.
 *
 * Note that this destructor is automatically called when the `MainWindow`
 * object goes out of scope
 * or is explicitly destroyed using the `delete` operator.
 */
MainWindow::~MainWindow(){
    delete ui;
}

/**
 * Updates the style of the `buttonXSign` widget based on the text in the
 * `LineEditX` widget.
 *
 * This function is called when the text in the `LineEditX` widget is
 * changed. If the text is empty,
 * the function calls the `setGreenButtonStyle()` method to change the
 * appearance of the `buttonXSign`
 * widget to indicate that the value is positive.
 *
 * @param text A `QString` object containing the new text in the
 * `LineEditX` widget.
 *
 * @see setGreenButtonStyle()
 */
void MainWindow::onLineEditXTextChanged(const QString& text){
    if (text.isEmpty())
        setGreenButtonStyle(ui->buttonXSign);
}

/**
 * Updates the style of the `buttonYSign` widget based on the text in the
 * `LineEditY` widget.
 *
 * This function is called when the text in the `LineEditY` widget is changed.
 * If the text is empty,
 * the function calls the `setGreenButtonStyle()` method to change the
 * appearance of the `buttonYSign`
 * widget to indicate that the value is positive.
 *
 * @param text A `QString` object containing the new text in the
 * `LineEditY` widget.
 *
 * @see setGreenButtonStyle()
 */
void MainWindow::onLineEditYTextChanged(const QString& text){
    if (text.isEmpty())
        setGreenButtonStyle(ui->buttonYSign);
}

/**
 * Displays an error message dialog with the specified message.
 *
 * This function creates a `QMessageBox` object with the critical icon,
 * sets the window title and text
 * to the specified message, adds an "Ok" button, and displays the dialog.
 * This function is typically
 * called when an error occurs in the program and the user needs to be alerted.
 *
 * @param message A `QString` object containing the error message to display.
 */
void MainWindow::showErrorDialog(const QString& message) {
    QMessageBox errorMessage;
    errorMessage.setIcon(QMessageBox::Critical);
    errorMessage.setWindowTitle("Error");
    errorMessage.setText(message);
    errorMessage.setStandardButtons(QMessageBox::Ok);
    errorMessage.exec();
}

/**
 * Opens the user manual PDF file or a cloud-based manual URL, depending on
 * availability.
 *
 * This function is called when the user clicks the "Help" button. It attempts
 * to open the local user
 * manual PDF file located in the "/resources" directory. If the file cannot
 * be found or opened, the
 * function displays a warning message. If the file is successfully opened,
 * it is displayed using the
 * default application for PDF files. If the local manual cannot be opened or
 * is not available, the
 * function opens the cloud-based manual URL in the user's default web browser.
 *
 * If the cloud-based manual URL is opened, the function does not display any
 * warning message.
 */
void MainWindow::onButtonHelpClicked() {
    QString manualFilePath = QCoreApplication::applicationDirPath() +
                             "/resources/user_manual.pdf";
    QUrl manualFileUrl = QUrl::fromLocalFile(manualFilePath);
    if (!QDesktopServices::openUrl(manualFileUrl)) {
        QMessageBox::warning(this,
                             tr("Error"),
                             tr("No se puede abrir el manual local."));
    }
    else{
    QDesktopServices::openUrl(QUrl(
"https://estudianteccr-my.sharepoint.com/:w:/g/personal"
"/carlos_andres12001_estudiantec_cr"
"/ERbrWpZKlxNPvpSA8ychQxIBlg1tXkwrePMdH7psgyrorg?e=FIttP1",
            QUrl::TolerantMode));
    }
}

/**
 * Clears the input field for the X value and resets the associated sign
 * button and Y value.
 *
 * This function is called when the user clicks the "Clear" button.
 * It clears the input field for the
 * X value and sets the associated sign button to green to indicate that the
 * input is valid. It also
 * calls the "resetYAndEqual()" function to clear the Y value and the equal
 * sign button.
 */
void MainWindow::onButtonClearClicked() {
    ui->lineEditX->clear();
    setGreenButtonStyle(ui->buttonXSign);
    resetYAndEqual();
}

/**
 * Calculates the division of 1/x and displays the result.
 *
 * This function is called when the user clicks the "1/x" button. It
 * checks if the input value for X
 * is correct and calculates the division of 1/x using the "divi_t"
 * function from the "funtrans"
 * namespace. If the input value is zero, it shows an error dialog.
 * It then displays the result in
 * the "plaintTextEqual" text field.
 */
void MainWindow::onButtonDiviClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    if (x == 0) {
        showErrorDialog("Valor de x no permitido "
                        "(debe ser distinto de cero)");
        return;
    }

    decimal_50_digits result = funtrans::divi_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

/**
 * Calculates the exponential function of x and displays the result.
 *
 * This function is called when the user clicks the "exp" button.
 * It checks if the input value for X
 * is correct and calculates the exponential function of x using the
 * "exp_t" function from the
 * "funtrans" namespace. It then displays the result in the
 * "plaintTextEqual" text field.
 */
void MainWindow::onButtonExpClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    decimal_50_digits result = funtrans::exp_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

/**
 * This function is called when the "sin" button is clicked in the main window.
 * It calculates the sin of the input value and displays the result in the
 * "equal" text box.
 * If the input value is incorrect, the function returns without doing anything.
 */
void MainWindow::onButtonSinClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    decimal_50_digits result = funtrans::sin_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

/**
 * This function is called when the "cos" button is clicked in the main window.
 * It calculates the cosine of the input value and displays the result in the
 * "equal" text box.
 * If the input value is incorrect, the function returns without doing anything.
 */
void MainWindow::onButtonCosClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    decimal_50_digits result = funtrans::cos_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

/**
 * This function is called when the "tan" button is clicked in the main window.
 * It calculates the tangent of the input value and displays the result in the
 * "equal" text box.
 * If the input value is incorrect or not allowed, the function displays an
 * error dialog and returns.
 */
void MainWindow::onButtonTanClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    if(funtrans::is_mult_pi_divi2(x)){
        showErrorDialog("Valor de x no permitido "
                        "(x no puede ser (2k+1)*pi/2)");
        return;
    }

    decimal_50_digits result = funtrans::tan_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

/**
 * @brief Slot function that is called when the "Ln" button is clicked.
 *
 * This function calculates the natural logarithm of the input value x and
 * displays the result in the "equal" field. If the input value is invalid,
 * an error message is displayed and the function returns without calculating
 * the result.
 *
 * @pre The input value x must be greater than zero.
 *
 * @post The natural logarithm of the input value x is displayed in the
 *       "equal" field.
 */
void MainWindow::onButtonLnClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    if(ui->buttonXSign->text().toStdString()!="+"){
        showErrorDialog("Valor de x no permitido"
                        "(deben ser mayores que cero)");
        return;
    }

    if (x <= 0) {
        showErrorDialog("Valor de x no permitido "
                        "(debe ser mayor que cero)");
        return;
    }

    decimal_50_digits result = funtrans::ln_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

/**
 * @brief Slot function that is called when the "Log10" button is clicked.
 *
 * This function calculates the base-10 logarithm of the input value x and
 * displays the result in the "equal" field. If the input value is invalid,
 * an error message is displayed and the function returns without calculating
 * the result.
 *
 * @pre The input value x must be greater than zero.
 *
 * @post The base-10 logarithm of the input value x is displayed in the
 *       "equal" field.
 */
void MainWindow::onButtonLog10Clicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    if (x <= 0) {
        showErrorDialog("Valor de x no permitido "
                        "(debe ser mayor que cero)");
        return;
    }

    decimal_50_digits result = funtrans::log10_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

/**
 * @brief Slot function that is called when the "Log(y)" button is clicked.
 *
 * This function calculates the logarithm of the input value y with respect to
 * the base-x and displays the result in the "equal" field. If the input values
 * are invalid, an error message is displayed and the function returns without
 * calculating the result.
 *
 * @pre The input values x and y must be greater than zero.
 *
 * @post The logarithm of the input value y with respect to the base-x is
 *       displayed in the "equal" field.
 */
void MainWindow::onButtonLogyClicked() {
    if (incorrectInputX())
        return;
    if (incorrectInputY())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    decimal_50_digits y( ui->lineEditY->text().toStdString());
    resetEqual();

    if (x <= 0 || y <= 0) {
        showErrorDialog("Valores de x e y no permitidos "
                        "(deben ser mayores que cero)");
        return;
    }

    decimal_50_digits result = funtrans::log_t(y, x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

/**
 * @brief Slot function that is called when the "x^y" button is clicked.
 *
 * This function calculates the power of the input value x raised to the power
 * of the input value y and displays the result in the "equal" field. If the
 * input
 * values are invalid, an error message is displayed and the function returns
 * without calculating the result.
 *
 * @pre The input value x must be greater than zero, and the input value y
 *      must be either a positive integer or a real number when x is positive.
 *
 * @post The power of the input value x raised to the power of the input value
 * y
 *       is displayed in the "equal" field.
 */
void MainWindow::onButtonPowerClicked() {
    if (incorrectInputX())
        return;
    if (incorrectInputY())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    decimal_50_digits y( ui->lineEditY->text().toStdString());
    resetEqual();

    if(y==0){
        ui->plaintTextEqual->setPlainText("1");
        return;
    }

    if(!funtrans::is_positive_integer(y) &&
    ui->buttonXSign->text().toStdString()!="+"){
        showErrorDialog("Valor de x no permitido"
                         " (para un y real "
                         " x no puede ser negativo.)");
        return;
    }

    auto result = funtrans::power_t(x, y);
    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

/**
 * @brief Slot function that is called when the "Sinh" button is clicked.
 *
 * This function calculates the hyperbolic sine of the input value x and
 * displays the result in the "equal" field. If the input value is invalid,
 * an error message is displayed and the function returns without calculating
 * the result.
 *
 * @post The hyperbolic sine of the input value x is displayed in the
 *       "equal" field.
 */
void MainWindow::onButtonSinhClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    decimal_50_digits result = funtrans::sinh_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

/**
 * @brief Slot function that is called when the "Cosh" button is clicked.
 *
 * This function calculates the hyperbolic cosine of the input value x and
 * displays the result in the "equal" field. If the input value is invalid,
 * an error message is displayed and the function returns without calculating
 * the result.
 *
 * @post The hyperbolic cosine of the input value x is displayed in the
 *       "equal" field.
 */
void MainWindow::onButtonCoshClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    decimal_50_digits result = funtrans::cosh_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

/**
 * @brief Slot function that is called when the "Sqrt" button is clicked.
 *
 * This function calculates the square root of the input value x and
 * displays the result in the "equal" field. If the input value is invalid,
 * an error message is displayed and the function returns without calculating
 * the result.
 *
 * @pre The input value x must be greater than or equal to zero.
 *
 * @post The square root of the input value x is displayed in the
 *       "equal" field.
 */
void MainWindow::onButtonSqrtClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    if(ui->buttonXSign->text().toStdString()!="+"){
        showErrorDialog("Valor de x no permitido"
                        "(deben ser mayores que cero)");
        return;
    }

    if (x < 0) {
        showErrorDialog("Valor de x no permitido "
                        "(debe ser mayor o igual que cero)");
        return;
    }

    decimal_50_digits result = funtrans::sqrt_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

/**
 * @brief Slot function that is called when the "Tanh" button is clicked.
 *
 * This function calculates the hyperbolic tangent of the input value x and
 * displays the result in the "equal" field. If the input value is invalid,
 * an error message is displayed and the function returns without calculating
 * the result.
 *
 * @post The hyperbolic tangent of the input value x is displayed in the
 *       "equal" field.
 */
void MainWindow::onButtonTanhClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    decimal_50_digits result = funtrans::tanh_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

/**
 * @brief Slot function that is called when the "Root" button is clicked.
 *
 * This function calculates the y-th root of the input value x and displays
 * the result in the "equal" field. If the input values are invalid, an error
 * message is displayed and the function returns without calculating the result.
 *
 * @pre The input value x must be greater than or equal to zero if y is even.
 *      The input value y must be a positive integer if you want to use decimal
 *      values use power(x,y).
 *
 * @post The y-th root of the input value x is displayed in the "equal" field.
 *       If the input value x is negative and y is odd, the result is displayed
 *       with a minus sign.
 */
void MainWindow::onButtonRootClicked() {
    if (incorrectInputX())
        return;
    if (incorrectInputY())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    decimal_50_digits y( ui->lineEditY->text().toStdString());
    resetEqual();


    if (y==0) {
        showErrorDialog("Valor de y no permitido");
        return;
    }
    if (x==0) {
        ui->plaintTextEqual->setPlainText("0");
        return;
    }

    if(ui->buttonYSign->text().toStdString()!="+"){
        showErrorDialog("Valor de y no permitido"
                        "(tiene que ser entero si quieres negativos"
                        " utiliza power(x, y)).");
        return;
    }

    if (!funtrans::is_positive_integer(y)) {
        showErrorDialog("Valor de y no permitido "
                        "(tiene que ser entero si quieres usar decimales"
                        " utiliza power(x, y)).");
        return;
    }

    int y_int = static_cast<int>(floor(y));

    if(ui->buttonXSign->text().toStdString()!="+"&&y_int%2==0){
        showErrorDialog("Valor de x no permitido "
                        "(ya que tiene que ser un valor positivo "
                        "porque y es par).");
        return;
    }

    decimal_50_digits result = funtrans::root_t( funtrans::abs_t(x),
                                                 y_int);
    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));

    if(ui->buttonXSign->text().toStdString()!="+"&&y_int%2!=0)
        ui->plaintTextEqual->setPlainText("-"+
                ui->plaintTextEqual->toPlainText());
}

/**
 * @brief Slot function that is called when the "Asin" button is clicked.
 *
 * This function calculates the arcsine of the input value x and displays the
 * result in the "equal" field. If the input value is invalid, an error message
 * is displayed and the function returns without calculating the result.
 *
 * @pre The input value x must be between -1 and 1 (inclusive).
 *
 * @post The arcsine of the input value x is displayed in the "equal" field.
 */
void MainWindow::onButtonAsinClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    if (x < -1 || x > 1) {
        showErrorDialog("Valor de x no permitido"
                                "x debe ser -1<x<1");
        return;
    }

    decimal_50_digits result = funtrans::asin_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

/**
 * @brief Slot function that is called when the "Acos" button is clicked.
 *
 * This function calculates the arccosine of the input value x and displays the
 * result in the "equal" field. If the input value is invalid, an error message
 * is displayed and the function returns without calculating the result.
 *
 * @pre The input value x must be between -1 and 1 (inclusive).
 *
 * @post The arccosine of the input value x is displayed in the "equal" field.
 */
void MainWindow::onButtonAcosClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    if (x < -1 || x > 1) {
        showErrorDialog("Valor de x no permitido"
                        "x debe ser -1<x<1");
        return;
    }

    decimal_50_digits result = funtrans::acos_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

/**
 * @brief Slot function that is called when the "Atan" button is clicked.
 *
 * This function calculates the arctangent of the input value x and displays the
 * result in the "equal" field. If the input value is invalid, an error message
 * is displayed and the function returns without calculating the result.
 *
 * @post The arctangent of the input value x is displayed in the "equal" field.
 */
void MainWindow::onButtonAtanClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    decimal_50_digits result = funtrans::atan_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

/**
 * @brief Slot function that is called when the "Csc" button is clicked.
 *
 * This function calculates the cosecant of the input value x and displays the
 * result in the "equal" field. If the input value is invalid, an error message
 * is displayed and the function returns without calculating the result.
 *
 * @pre The input value x must not be an odd multiple of pi/2.
 *
 * @post The cosecant of the input value x is displayed in the "equal" field.
 */
void MainWindow::onButtonCscClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    decimal_50_digits result = funtrans::csc_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

/**
 * @brief Slot function that is called when the "Sec" button is clicked.
 *
 * This function calculates the secant of the input value x and displays the
 * result in the "equal" field. If the input value is invalid, an error message
 * is displayed and the function returns without calculating the result.
 *
 * @pre The input value x must not be a multiple of pi/2.
 *
 * @post The secant of the input value x is displayed in the "equal" field.
 */
void MainWindow::onButtonSecClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    decimal_50_digits result = funtrans::sec_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

/**
 * @brief Slot function that is called when the "Cot" button is clicked.
 *
 * This function calculates the cotangent of the input value x and displays the
 * result in the "equal" field. If the input value is invalid, an error message
 * is displayed and the function returns without calculating the result.
 *
 * @pre The input value x must not be equal to k*pi/2 or (2k+1)*pi/2, where k is
 * an integer.
 *
 * @post The cotangent of the input value x is displayed in the "equal" field.
 */
void MainWindow::onButtonCotClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    if(funtrans::is_mult_pi_divi2(x)||funtrans::is_mult_pi(x)){
        showErrorDialog("Valor de x no permitido "
                        "(x no puede ser (2k+1)*pi/2) "
                        "(x no puede ser k*pi/2)");
        return;
    }

    decimal_50_digits result = funtrans::cot_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

/**
 * @brief Slot function that is called when the "x!" button is clicked.
 *
 * This function calculates the factorial of the input value x and displays the
 * result in the "equal" field. If the input value is invalid, an error message
 * is displayed and the function returns without calculating the result.
 *
 * @pre The input value x must be a non-negative integer.
 *
 * @post The factorial of the input value x is displayed in the "equal" field.
 */
void MainWindow::onButtonFactorialClicked() {
    if (incorrectInputX())
        return;
    decimal_50_digits x(ui->lineEditX->text().toStdString());
    resetYAndEqual();

    if(ui->buttonXSign->text().toStdString()!="+"){
        showErrorDialog("Valor de x no permitido");
        return;
    }

    if (x<0) {
        showErrorDialog("Valor de x no permitido");
        return;
    }

    decimal_50_digits result = funtrans::factorial_t(x);

    ui->plaintTextEqual->setPlainText(QString(result.str().c_str()));
}

/**
 * @brief Slot function that is called when the "pi" button is clicked.
 *
 * This function retrieves the value of pi from the funtrans namespace and asks
 * the user where they would like to use the value. If the user selects the "x"
 * button, the value is displayed in the "x" field; if the user selects the "y"
 * button, the value is displayed in the "y" field; otherwise, the value is
 * displayed in the "x" field by default.
 *
 * @post The value of pi is displayed in the selected input field.
 */
void MainWindow::onButtonPIClicked() {
    decimal_50_digits pi = funtrans::pi_t;

    QMessageBox msgBox;
    msgBox.setText("En qué desea establecer el valor de PI?");

    QPushButton *xButton = msgBox.addButton(tr("x"),
                                            QMessageBox::ActionRole);
    QPushButton *yButton = msgBox.addButton(tr("y"),
                                            QMessageBox::ActionRole);

    msgBox.exec();

    if (msgBox.clickedButton() == xButton)
        ui->lineEditX->setText(QString(pi.str().c_str()));
    else if (msgBox.clickedButton() == yButton)
        ui->lineEditY->setText(QString(pi.str().c_str()));
    else
        ui->lineEditX->setText(QString(pi.str().c_str()));
}

/**
 * @brief Slot function that is called when the "+/-" button for the x input is
 * clicked.
 *
 * This function toggles the sign of the x input field and updates the styling
 * of the
 * button accordingly. If the current label of the button is "-", the function
 * removes
 * any "-" signs from the x input field and sets the button to a green color to
 * indicate
 * that the number is positive. If the current label of the button is "+", the
 * function
 * adds a "-" sign to the x input field and sets the button to a red color to
 * indicate
 * that the number is negative.
 *
 * @post The sign of the x input field is toggled and the button is updated to reflect
 * the new sign.
 */
void MainWindow::onButtonXSignClicked() {
    string label = ui->buttonXSign->text().toStdString();
    string str_num =  ui->lineEditX->text().isEmpty()? "" :
                        ui->lineEditX->text().toStdString();
    if(label != "+"){
        str_num.erase(remove(str_num.begin(), str_num.end(),
                             '-'),
                      str_num.end());
        ui->lineEditX->setText(QString::fromStdString(str_num));
        setGreenButtonStyle(ui->buttonXSign);
    }
    else{
        ui->lineEditX->setText("-"+QString::fromStdString(str_num));
        setRedButtonStyle(ui->buttonXSign);
    }
}

/**
 * @brief Slot for handling the click event of the Y-sign button.
 *
 * This function is called when the Y-sign button is clicked. It checks the
 * current text
 * label of the button to determine whether the current value in the Y line
 * edit should
 * be negated. If the label is not "+", the minus sign is removed from the
 * current value
 * in the Y line edit and the button is styled with a green background.
 * If the label is
 * "+", the minus sign is added to the current value in the Y line edit and
 * the button is
 * styled with a red background.
 *
 * @return void
 */
void MainWindow::onButtonYSignClicked() {
    string label = ui->buttonYSign->text().toStdString();
    string str_num =  ui->lineEditY->text().isEmpty() ? "" :
            ui->lineEditY->text().toStdString();
    if(label != "+"){
        str_num.erase(remove(str_num.begin(), str_num.end(),
                             '-'),
                         str_num.end());
        ui->lineEditY->setText(QString::fromStdString(str_num));
        setGreenButtonStyle(ui->buttonYSign);
    }
    else{
        ui->lineEditY->setText("-"+QString::fromStdString(str_num));
        setRedButtonStyle(ui->buttonYSign);
    }
}

/**
 * @brief Sets the style of the specified button to display a green background
 * and a plus sign.
 *
 * This function sets the text of the specified button to "+" and applies a CSS
 * style sheet to the button to give it a green background and other visual
 * properties. This is intended to be used as a visual cue to indicate that a
 * certain action will result in a positive value.
 *
 * @param button A pointer to the QPushButton object whose style is to be set.
 * @return void
 */
void MainWindow::setGreenButtonStyle(QPushButton* button){
    button->setText("+");
    button->setStyleSheet(
            "QPushButton {"
            "   border: none;"
            "   border-radius: 5px;"
            "   color: white;"
            "   font-size: 22px;"
            "   font-weight: bold;"
            "   padding: 10px 20px;"
            "   background-color: #2E8B57;"
            "}"
    );
}

/**
 * @brief Sets the style of the specified button to display a red background and
 * a  minus sign.
 *
 * This function sets the text of the specified button to "-" and applies a CSS
 * style sheet to the button to give it a red background and other visual
 * properties. This is intended to be used as a visual cue to indicate that a
 * certain action will result in a negative value.
 *
 * @param button A pointer to the QPushButton object whose style is to be set.
 * @return void
 */
void MainWindow::setRedButtonStyle(QPushButton* button){
    button->setText("-");
    button->setStyleSheet(
            "QPushButton {"
            "   border: none;"
            "   border-radius: 5px;"
            "   color: white;"
            "   font-size: 22px;"
            "   font-weight: bold;"
            "   padding: 10px 20px;"
            "   background-color: #de505c;"
            "}"
    );
}

/**
 * @brief Resets the value in the Y line edit and the equals button to their
 * default states.
 *
 * This function clears the current text in the Y line edit, sets the style
 * of the Y- sign button to display a green background and a plus sign, and
 * calls the  resetEqual() function to reset the style of the equals button.
 * This is intended to  be used as a way to reset the calculator interface
 * to its initial state.
 *
 * @return void
 */
void MainWindow::resetYAndEqual() {
    ui->lineEditY->clear();
    setGreenButtonStyle(ui->buttonYSign);
    resetEqual();
}

/**
 * @brief Resets the text in the equals line edit to its default state.
 *
 * This function clears the current text in the equals line edit. This is intended
 * to be used as a way to reset the calculator interface to its initial state.
 *
 * @return void
 */
void MainWindow::resetEqual() {
    ui->plaintTextEqual->clear();
}

/**
 * @brief Checks whether the value entered in the X line edit is valid or not.
 *
 * This function checks whether the text entered in the X line edit is empty or
 * not
 * a real number. If the text is empty, an error dialog is displayed with an
 * appropriate error message and the function returns true. If the text is not a
 * real number, an error dialog is displayed with an appropriate error message
 * and the function returns true. If the text is a valid real number, the
 * function returns false.
 *
 * @return A boolean value indicating whether the input is incorrect (true) or
 *         correct (false).
 */
bool MainWindow::incorrectInputX(){
    if (ui->lineEditX->text().isEmpty()) {
        showErrorDialog("Valor de x está vació.");
        return true;
    }
    else if (funtrans::notRealNumber(ui->lineEditX->text().toStdString())){
        showErrorDialog("Valor de x no es un numero real.");
        return true;
    }
    else
        return false;
}

/**
 * @brief Checks whether the value entered in the Y line edit is valid or not.
 *
 * This function checks whether the text entered in the Y line edit is empty or
 * not
 * a real number. If the text is empty, an error dialog is displayed with an
 * appropriate error message and the function returns true. If the text is not a
 * real number, an error dialog is displayed with an appropriate error message
 * and the function returns true. If the text is a valid real number, the
 * function returns false.
 *
 * @return A boolean value indicating whether the input is incorrect (true) or
 *         correct (false).
 */
bool MainWindow::incorrectInputY(){
    if (ui->lineEditY->text().isEmpty()) {
        showErrorDialog("Valor de y está vació.");
        return true;
    }
    else if (funtrans::notRealNumber(ui->lineEditY->text().toStdString())){
        showErrorDialog("Valor de y no es un numero real.");
        return true;
    }
    else
        return false;
}
