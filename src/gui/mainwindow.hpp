#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../header.hpp"
#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief The MainWindow class is the main window of the application.
 *
 * This class inherits from QMainWindow and represents the main window of the
 * application. It contains various user interface elements, such as line edits,
 * buttons, and labels, that allow the user to perform various calculations. The
 * class also contains various member functions that implement the logic of
 * the application.
 *
 * The Q_OBJECT macro must be used in order to support signals and slots
 * mechanisms in the class.
 */
class MainWindow : public QMainWindow{
    Q_OBJECT

public:

    /**
     * @brief Constructor for the MainWindow class.
     *
     * @param parent A pointer to the parent widget of the main window.
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor for the MainWindow class.
     */
    ~MainWindow() override;

private:

    /**
     * @brief Displays an error dialog with the specified message.
     *
     * This static function displays an error dialog with the specified message.
     *
     * @param message The error message to display in the dialog.
     */
    static void showErrorDialog(const QString& message);

    /**
     * @brief Sets the style of the specified button to display a green background
     *        and a plus sign.
     *
     * This static function sets the style of the specified button to display a
     * green background and a plus sign.
     *
     * @param button A pointer to the QPushButton object whose style is to be set.
     */
    static void setGreenButtonStyle(QPushButton* button);

    /**
     * @brief Sets the style of the specified button to display a red background
     *        and a minus sign.
     *
     * This static function sets the style of the specified button to display a
     * red background and a minus sign.
     *
     * @param button A pointer to the QPushButton object whose style is to be set.
     */
    static void setRedButtonStyle(QPushButton* button);

    /**
     * @brief Checks whether the value entered in the X line edit is valid or not.
     *
     * This function checks whether the text entered in the X line edit is empty
     * or
     * not a real number. If the text is empty or not a real number, an error
     * dialog
     * is displayed with an appropriate error message and the function returns
     * true.
     * If the text is a valid real number, the function returns false.
     *
     * @return A boolean value indicating whether the input is incorrect (true)
     * or
     *         correct (false).
     */
    bool incorrectInputX();

    /**
     * @brief Checks whether the value entered in the Y line edit is valid or
     * not.
     *
     * This function checks whether the text entered in the Y line edit is empty
     * or
     * not a real number. If the text is empty or not a real number, an error
     * dialog
     * is displayed with an appropriate error message and the function returns
     * true.
     * If the text is a valid real number, the function returns false.
     *
     * @return A boolean value indicating whether the input is incorrect (true)
     * or
     *         correct (false).
     */
    bool incorrectInputY();

    /**
     * @brief Resets the value in the Y line edit and the equals button to their
     *        default states.
     *
     * This function clears the current text in the Y line edit, sets the style
     * of
     * the Y-sign button to display a green background and a plus sign, and calls
     * the resetEqual() function to reset the style of the equals button.
     */
    void resetYAndEqual();

    /**
     * @brief Resets the text in the equals line edit to its default state.
     *
     * This function clears the current text in the equals line edit.
     */
    void resetEqual();

    /**
     * @brief Slot function that is called when the text in the X line edit changes.
     *
     * This function is called whenever the text in the X line edit changes. It calls
     * the incorrectInputX() function to check whether the new text is valid or not,
     * and sets the style of the equals button to indicate whether the result is
     * valid or invalid.
     *
     * @param text The new text entered in the X line edit.
     */
    void onLineEditXTextChanged(const QString& text);

    /**
     * @brief Slot function that is called when the text in the Y line edit changes.
     *
     * This function is called whenever the text in the Y line edit changes. It calls
     * the incorrectInputY() function to check whether the new text is valid or not,
     * and sets the style of the equals button to indicate whether the result is
     * valid or invalid.
     *
     * @param text The new text entered in the Y line edit.
     */
    void onLineEditYTextChanged(const QString& text);

    Ui::MainWindow *ui;

private slots:

    /**
     * @brief Slot function that is called when the Help button is clicked.
     *
     * This function is called whenever the Help button is clicked. It displays
     * a
     * message box with information about how to use the application.
     */
    void onButtonHelpClicked();

    /**
     * @brief Slot function that is called when the Clear button is clicked.
     *
     * This function is called whenever the Clear button is clicked. It clears
     * the
     * text in the X and Y line edits and sets the style of the equals button to
     * its
     * default state.
     */
    void onButtonClearClicked();

    /**
     * @brief Slot function that is called when the Divide button is clicked.
     *
     * This function is called whenever the Divide button is clicked. It checks
     * whether the input in the X and Y line edits is valid and performs the division
     * operation if possible. If the input is not valid, an error dialog is displayed
     * with an appropriate error message.
     */
    void onButtonDiviClicked();

    /**
     * @brief Slot function that is called when the Exponent button is clicked.
     *
     * This function is called whenever the Exponent button is clicked. It
     * checks
     * whether the input in the X and Y line edits is valid and performs the
     * exponent
     * operation if possible. If the input is not valid, an error dialog is
     * displayed
     * with an appropriate error message.
     */
    void onButtonExpClicked();

    /**
     * @brief Slot function that is called when the Sine button is clicked.
     *
     * This function is called whenever the Sine button is clicked. It checks
     * whether
     * the input in the X line edit is valid and performs the sine operation if
     * possible. If the input is not valid, an error dialog is displayed with an
     * appropriate error message.
     */
    void onButtonSinClicked();

    /**
     * @brief Slot function that is called when the Cosine button is clicked.
     *
     * This function is called whenever the Cosine button is clicked. It checks
     * whether the input in the X line edit is valid and performs the cosine
     * operation
     * if possible. If the input is not valid, an error dialog is displayed
     * with an
     * appropriate error message.
     */
    void onButtonCosClicked();

    /**
     * @brief Slot function that is called when the Tangent button is clicked.
     *
     * This function is called whenever the Tangent button is clicked. It checks
     * whether the input in the X line edit is valid and performs the tangent
     * operation
     * if possible. If the input is not valid, an error dialog is displayed
     * with an
     * appropriate error message.
     */
    void onButtonTanClicked();

    /**
     * @brief Slot function that is called when the Natural Logarithm button
     * is clicked.
     *
     * This function is called whenever the Natural Logarithm button is clicked.
     * It checks
     * whether the input in the X line edit is valid and performs the natural
     * logarithm
     * operation if possible. If the input is not valid, an error dialog is
     * displayed with an
     * appropriate error message.
     */
    void onButtonLnClicked();

    /**
     * @brief Slot function that is called when the Logarithm base Y button is
     * clicked.
     *
     * This function is called whenever the Logarithm base Y button is clicked.
     * It checks
     * whether the input in the X and Y line edits is valid and performs the
     * logarithm
     * operation with base Y if possible. If the input is not valid, an error
     * dialog is
     * displayed with an appropriate error message.
     */
    void onButtonLogyClicked();

    /**
     * @brief Slot function that is called when the Power button is clicked.
     *
     * This function is called whenever the Power button is clicked. It checks
     * whether
     * the input in the X and Y line edits is valid and performs the power
     * operation if
     * possible. If the input is not valid, an error dialog is displayed with an
     * appropriate error message.
     */
    void onButtonPowerClicked();

    /**
     * @brief Slot function that is called when the Hyperbolic Sine button is
     * clicked.
     *
     * This function is called whenever the Hyperbolic Sine button is clicked.
     * It checks
     * whether the input in the X line edit is valid and performs the
     * hyperbolic sine
     * operation if possible. If the input is not valid, an error dialog is
     * displayed with
     * an appropriate error message.
     */
    void onButtonSinhClicked();

    /**
     * @brief Slot function that is called when the Hyperbolic Cosine button
     * is clicked.
     *
     * This function is called whenever the Hyperbolic Cosine button is clicked.
     * It checks
     * whether the input in the X line edit is valid and performs the hyperbolic
     * cosine
     * operation if possible. If the input is not valid, an error dialog is
     * displayed with
     * an appropriate error message.
     */
    void onButtonCoshClicked();

    /**
     * @brief Slot function that is called when the Square Root button is clicked.
     *
     * This function is called whenever the Square Root button is clicked. It
     *
     * whether the input in the X line edit is valid and performs the square
     * root
     * operation if possible. If the input is not valid, an error dialog is
     * displayed
     * with an appropriate error message.
 */
    void onButtonSqrtClicked();

    /**
     * @brief Slot function that is called when the Hyperbolic Tangent button
     * is clicked.
     *
     * This function is called whenever the Hyperbolic Tangent button is clicked.
     * It checks
     * whether the input in the X line edit is valid and performs the hyperbolic
     * tangent
     * operation if possible. If the input is not valid, an error dialog is
     * displayed with
     * an appropriate error message.
     */
    void onButtonTanhClicked();

    /**
     * @brief Slot function that is called when the Nth Root button is clicked.
     *
     * This function is called whenever the Nth Root button is clicked. It
     * checks
     * whether the input in the X and Y line edits is valid and performs the
     * Nth root
     * operation if possible. If the input is not valid, an error dialog is
     * displayed with
     * an appropriate error message.
     */
    void onButtonRootClicked();

    /**
     * @brief Slot function that is called when the Arcsine button is clicked.
     *
     * This function is called whenever the Arcsine button is clicked.
     * It checks whether
     * the input in the X line edit is valid and performs the arcsine operatio
     * n if
     * possible. If the input is not valid, an error dialog is displayed with an
     * appropriate error message.
     */
    void onButtonAsinClicked();

    /**
     * @brief Slot function that is called when the Arctangent button is clicked.
     *
     * This function is called whenever the Arctangent button is clicked. It
     * checks whether
     * the input in the X line edit is valid and performs the arctangent
     * operation if
     * possible. If the input is not valid, an error dialog is displayed with an
     * appropriate error message.
     */
    void onButtonAtanClicked();

    /**
     * @brief Slot function that is called when the Cosecant button is clicked.
     *
     * This function is called whenever the Cosecant button is clicked. It
     * checks whether
     * the input in the X line edit is valid and performs the cosecant
     * operation if
     * possible. If the input is not valid, an error dialog is displayed with an
     * appropriate error message.
     */
    void onButtonCscClicked();

    /**
     * @brief Slot function that is called when the Secant button is clicked.
     *
     * This function is called whenever the Secant button is clicked. It checks
     * whether
     * the input in the X line edit is valid and performs the secant operation if
     * possible. If the input is not valid, an error dialog is displayed with an
     * appropriate error message.
     */
    void onButtonSecClicked();

    /**
     * @brief Slot function that is called when the Cotangent button is clicked.
     *
     * This function is called whenever the Cotangent button is clicked.
     * It checks whether
     * the input in the X line edit is valid and performs the cotangent
     * operation if
     * possible. If the input is not valid, an error dialog is displayed with an
     * appropriate error message.
     */
    void onButtonCotClicked();

    /**
     * @brief Slot function that is called when the Factorial button is clicked.
     *
     * This function is called whenever the Factorial button is clicked.
     * It checks whether
     * the input in the X line edit is valid and performs the factorial
     * operation if
     * possible. If the input is not valid, an error dialog is displayed with an
     * appropriate error message.
     */
    void onButtonFactorialClicked();

    /**
     * @brief Slot function that is called when the PI button is clicked.
     *
     * This function is called whenever the PI button is clicked. It sets the
     * value of
     * the X line edit to the value of pi.
     */
    void onButtonPIClicked();

    /**
     * @brief Slot function that is called when the Arccosine button is clicked.
     *
     * This function is called whenever the Arccosine button is clicked. It
     * checks whether
     * the input in the X line edit is valid and performs the arccosine
     * operation if
     * possible. If the input is not valid, an error dialog is displayed with an
     * appropriate error message.
     */
    void onButtonAcosClicked();

    /**
     * @brief Slot function that is called when the Logarithm base 10 button
     * is clicked.
     *
     * This function is called whenever the Logarithm base 10 button is
     * clicked. It checks
     * whether the input in the X line edit is valid and performs the
     * logarithm with base 10
     * operation if possible. If the input is not valid, an error dialog
     * is displayed with an
     * appropriate error message.
     */
    void onButtonLog10Clicked();

    /**
     * @brief Slot function that is called when the X sign button is clicked.
     *
     * This function is called whenever the X sign button is clicked.
     * It toggles the sign of
     * the value in the X line edit.
     */
    void onButtonXSignClicked();

    /**
     * @brief Slot function that is called when the Y sign button is clicked.
     *
     * This function is called whenever the Y sign button is clicked.
     * It toggles the sign of
     * the value in the Y line edit.
     */
    void onButtonYSignClicked();

};
#endif // MAINWINDOW_H
