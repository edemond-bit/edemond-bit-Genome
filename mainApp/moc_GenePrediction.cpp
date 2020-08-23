/****************************************************************************
** Form1 meta object code from reading C++ file 'GenePrediction.h'
**
** Created: Sat Nov 27 12:06:42 2010
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.3   edited Aug 5 16:40 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "GenePrediction.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *Form1::className() const
{
    return "Form1";
}

QMetaObject *Form1::metaObj = 0;
static QMetaObjectCleanUp cleanUp_Form1( "Form1", &Form1::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString Form1::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Form1", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString Form1::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Form1", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* Form1::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QFrame::staticMetaObject();
    static const QUMethod slot_0 = {"apply", 0, 0 };
    static const QUMethod slot_1 = {"initializeFields", 0, 0 };
    static const QUMethod slot_2 = {"non_interactive_rstat_call", 0, 0 };
    static const QUMethod slot_3 = {"non_interactive_pval_call", 0, 0 };
    static const QUMethod slot_4 = {"InitializeApplication", 0, 0 };
    static const QUMethod slot_5 = {"Initialize_Namespace", 0, 0 };
    static const QUMethod slot_6 = {"browseFile_clicked", 0, 0 };
    static const QUMethod slot_7 = {"acceptPath_Ready_for_Computation", 0, 0 };
    static const QUMethod slot_8 = {"updateStatusView", 0, 0 };
    static const QUMethod slot_9 = {"setGUIState", 0, 0 };
    static const QUMethod slot_10 = {"nextForm_NI", 0, 0 };
    static const QUMethod slot_11 = {"previousForm_NI", 0, 0 };
    static const QUParameter param_slot_12[] = {
	{ "nameSpaceid", &static_QUType_int, 0, QUParameter::In },
	{ "resultId", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_12 = {"linkResults", 2, param_slot_12 };
    static const QUParameter param_slot_13[] = {
	{ "fn", &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_13 = {"openFile", 1, param_slot_13 };
    static const QUParameter param_slot_14[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_14 = {"sequenceFileName_textChanged", 1, param_slot_14 };
    static const QUMethod slot_15 = {"computeOrfNowPushButton_clicked", 0, 0 };
    static const QUMethod slot_16 = {"goToNextPageORF", 0, 0 };
    static const QUMethod slot_17 = {"goToPreviousPageORF", 0, 0 };
    static const QUMethod slot_18 = {"goToPreviousPageRANDOM", 0, 0 };
    static const QUMethod slot_19 = {"goToNextPageRANDOM", 0, 0 };
    static const QUMethod slot_20 = {"goToNextPageRStatistics", 0, 0 };
    static const QUMethod slot_21 = {"goToPreviousPageRStatistics", 0, 0 };
    static const QUMethod slot_22 = {"goToNextPagePValue", 0, 0 };
    static const QUMethod slot_23 = {"goToPreviousPagePValue", 0, 0 };
    static const QUMethod slot_24 = {"pushButton14_clicked", 0, 0 };
    static const QUMethod slot_25 = {"initialize_max_min_fields", 0, 0 };
    static const QUMethod slot_26 = {"pushButton15_clicked", 0, 0 };
    static const QUMethod slot_27 = {"pushButton20_clicked", 0, 0 };
    static const QUMethod slot_28 = {"pushButton12_clicked", 0, 0 };
    static const QUMethod slot_29 = {"orfRadio_clicked", 0, 0 };
    static const QUMethod slot_30 = {"predictionRadio_clicked", 0, 0 };
    static const QUMethod slot_31 = {"pushButton16_3_clicked", 0, 0 };
    static const QUMethod slot_32 = {"pushButton16_2_clicked", 0, 0 };
    static const QUMethod slot_33 = {"pushButton16_clicked", 0, 0 };
    static const QUMethod slot_34 = {"pushButton19_clicked", 0, 0 };
    static const QUMethod slot_35 = {"radioButton7_clicked", 0, 0 };
    static const QUMethod slot_36 = {"radioButton8_clicked", 0, 0 };
    static const QUMethod slot_37 = {"radioButton9_clicked", 0, 0 };
    static const QUMethod slot_38 = {"radioButton10_clicked", 0, 0 };
    static const QUParameter param_slot_39[] = {
	{ "b", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_39 = {"checkBox2_toggled", 1, param_slot_39 };
    static const QUMethod slot_40 = {"pushButton15_released", 0, 0 };
    static const QUMethod slot_41 = {"pushButton26_clicked", 0, 0 };
    static const QUParameter param_slot_42[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod slot_42 = {"widgetStack_aboutToShow", 1, param_slot_42 };
    static const QUParameter param_slot_43[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_43 = {"lineEdit3_textChanged", 1, param_slot_43 };
    static const QUMethod slot_44 = {"enablePusButton14", 0, 0 };
    static const QUParameter param_slot_45[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_45 = {"lineEdit4_textChanged", 1, param_slot_45 };
    static const QUMethod slot_46 = {"pushButton27_clicked", 0, 0 };
    static const QUMethod slot_47 = {"pushButton28_clicked", 0, 0 };
    static const QUMethod slot_48 = {"pushButton25_pressed", 0, 0 };
    static const QUMethod slot_49 = {"pushButton3_clicked", 0, 0 };
    static const QUMethod slot_50 = {"pushButton16_4_released", 0, 0 };
    static const QUMethod slot_51 = {"pushButton18_released", 0, 0 };
    static const QUMethod slot_52 = {"pushButton19_2_released", 0, 0 };
    static const QUMethod slot_53 = {"pushButton20_2_clicked", 0, 0 };
    static const QUMethod slot_54 = {"pushButton21_clicked", 0, 0 };
    static const QUMethod slot_55 = {"pushButton29_clicked", 0, 0 };
    static const QUMethod slot_56 = {"pushButton29_2_clicked", 0, 0 };
    static const QUMethod slot_57 = {"pushButton29_4_clicked", 0, 0 };
    static const QUParameter param_slot_58[] = {
	{ "flag", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_58 = {"nearest_neighbour_default", 1, param_slot_58 };
    static const QUParameter param_slot_59[] = {
	{ "rstat_or_p_flag", &static_QUType_int, 0, QUParameter::In },
	{ "flag", &static_QUType_int, 0, QUParameter::In },
	{ "count", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_59 = {"nearest_neighbour_default_1", 3, param_slot_59 };
    static const QUMethod slot_60 = {"pushButton27_2_5_clicked", 0, 0 };
    static const QUMethod slot_61 = {"pushButton27_2_6_clicked", 0, 0 };
    static const QUMethod slot_62 = {"pushButton27_2_7_clicked", 0, 0 };
    static const QUMethod slot_63 = {"pushButton27_2_8_clicked", 0, 0 };
    static const QUMethod slot_64 = {"pushButton29_5_clicked", 0, 0 };
    static const QUMethod slot_65 = {"pushButton29_2_2_clicked", 0, 0 };
    static const QUMethod slot_66 = {"pushButton29_4_2_clicked", 0, 0 };
    static const QUMethod slot_67 = {"pushButton27_2_clicked", 0, 0 };
    static const QUMethod slot_68 = {"pushButton27_2_2_clicked", 0, 0 };
    static const QUMethod slot_69 = {"pushButton27_2_3_clicked", 0, 0 };
    static const QUMethod slot_70 = {"pushButton27_2_4_clicked", 0, 0 };
    static const QUParameter param_slot_71[] = {
	{ "w", &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod slot_71 = {"tabWidget2_currentChanged", 1, param_slot_71 };
    static const QUMethod slot_72 = {"pushButton35_clicked", 0, 0 };
    static const QUMethod slot_73 = {"checkBox3_clicked", 0, 0 };
    static const QUMethod slot_74 = {"checkBox3_2_clicked", 0, 0 };
    static const QUMethod slot_75 = {"pushButton45_clicked", 0, 0 };
    static const QUMethod slot_76 = {"directoryChangedWarning", 0, 0 };
    static const QUMethod slot_77 = {"pushButton35_2_clicked", 0, 0 };
    static const QUMethod slot_78 = {"pushButton35_3_clicked", 0, 0 };
    static const QUParameter param_slot_79[] = {
	{ "widgetNo", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_79 = {"widgetStack5_aboutToShow", 1, param_slot_79 };
    static const QUMethod slot_80 = {"pushButton29_3_pressed", 0, 0 };
    static const QUMethod slot_81 = {"pushButton29_3_released", 0, 0 };
    static const QUMethod slot_82 = {"pushButton35_4_clicked", 0, 0 };
    static const QUMethod slot_83 = {"pushButton27_2_5_2_clicked", 0, 0 };
    static const QUMethod slot_84 = {"pushButton27_2_5_2_2_clicked", 0, 0 };
    static const QUMethod slot_85 = {"pushButton27_2_5_2_3_clicked", 0, 0 };
    static const QUMethod slot_86 = {"pushButton27_2_5_2_4_clicked", 0, 0 };
    static const QUMethod slot_87 = {"pushButton35_5_clicked", 0, 0 };
    static const QUMethod slot_88 = {"pushButton45_2_clicked", 0, 0 };
    static const QUMethod slot_89 = {"pushButton35_6_clicked", 0, 0 };
    static const QUMethod slot_90 = {"pushButton64_clicked", 0, 0 };
    static const QUMethod slot_91 = {"pushButton27_2_2_2_clicked", 0, 0 };
    static const QUMethod slot_92 = {"radioButton9_2_clicked", 0, 0 };
    static const QUMethod slot_93 = {"radioButton8_2_clicked", 0, 0 };
    static const QUMethod slot_94 = {"pushButton35_7_clicked", 0, 0 };
    static const QUMethod slot_95 = {"pushButton35_8_clicked", 0, 0 };
    static const QUMethod slot_96 = {"pushButton27_2_4_2_released", 0, 0 };
    static const QUMethod slot_97 = {"pushButton27_2_4_2_2_released", 0, 0 };
    static const QUMethod slot_98 = {"pushButton29_3_2_pressed", 0, 0 };
    static const QUMethod slot_99 = {"pushButton29_3_2_released", 0, 0 };
    static const QUMethod slot_100 = {"resultRadio_clicked", 0, 0 };
    static const QUMethod slot_101 = {"newSlot", 0, 0 };
    static const QUMethod slot_102 = {"pushButton50_clicked", 0, 0 };
    static const QUMethod slot_103 = {"pushButton50_2_clicked", 0, 0 };
    static const QUMethod slot_104 = {"pushButton50_3_clicked", 0, 0 };
    static const QUMethod slot_105 = {"pushButton50_2_4_clicked", 0, 0 };
    static const QUMethod slot_106 = {"closeSession_clicked", 0, 0 };
    static const QUMethod slot_107 = {"pushButton59_clicked", 0, 0 };
    static const QUMethod slot_108 = {"pushButton59_2_clicked", 0, 0 };
    static const QUMethod slot_109 = {"pushButton59_2_2_released", 0, 0 };
    static const QUMethod slot_110 = {"pushButton59_2_2_pressed", 0, 0 };
    static const QUMethod slot_111 = {"pushButton59_2_3_clicked", 0, 0 };
    static const QUMethod slot_112 = {"pushButton59_6_clicked", 0, 0 };
    static const QUMethod slot_113 = {"pushButton59_5_released", 0, 0 };
    static const QUMethod slot_114 = {"pushButton59_5_pressed", 0, 0 };
    static const QUMethod slot_115 = {"pushButton59_4_clicked", 0, 0 };
    static const QUMethod slot_116 = {"pushButton59_3_clicked", 0, 0 };
    static const QUMethod slot_117 = {"radioButton11_clicked", 0, 0 };
    static const QUMethod slot_118 = {"radioButton10_2_clicked", 0, 0 };
    static const QUMethod slot_119 = {"radioButton10_2_2_clicked", 0, 0 };
    static const QUMethod slot_120 = {"radioButton11_2_clicked", 0, 0 };
    static const QUMethod slot_121 = {"radioButton10_2_2_2_clicked", 0, 0 };
    static const QUMethod slot_122 = {"radioButton11_2_2_clicked", 0, 0 };
    static const QUMethod slot_123 = {"pushButton29_4_3_clicked", 0, 0 };
    static const QUMethod slot_124 = {"pushButton59_2_3_2_clicked", 0, 0 };
    static const QUMethod slot_125 = {"pushButton69_clicked", 0, 0 };
    static const QUMethod slot_126 = {"pushButton29_5_2_clicked", 0, 0 };
    static const QUMethod slot_127 = {"pushButton69_2_clicked", 0, 0 };
    static const QUMethod slot_128 = {"pushButton71_clicked", 0, 0 };
    static const QUMethod slot_129 = {"pushButton71_2_clicked", 0, 0 };
    static const QUMethod slot_130 = {"pushButton25_clicked", 0, 0 };
    static const QUParameter param_slot_131[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_131 = {"checkBox4_stateChanged", 1, param_slot_131 };
    static const QUMethod slot_132 = {"pushButton72_clicked", 0, 0 };
    static const QUMethod slot_133 = {"pushButton76_clicked", 0, 0 };
    static const QUMethod slot_134 = {"lineEdit8_textChanged", 0, 0 };
    static const QUMethod slot_135 = {"lineEdit9_textChanged", 0, 0 };
    static const QUMethod slot_136 = {"lineEdit8_3_textChanged", 0, 0 };
    static const QUMethod slot_137 = {"lineEdit9_3_textChanged", 0, 0 };
    static const QUMethod slot_138 = {"lineEdit8_2_textChanged", 0, 0 };
    static const QUMethod slot_139 = {"lineEdit9_2_textChanged", 0, 0 };
    static const QUMethod slot_140 = {"lineEdit8_3_2_textChanged", 0, 0 };
    static const QUMethod slot_141 = {"lineEdit9_3_2_textChanged", 0, 0 };
    static const QUMethod slot_142 = {"pushButton76_2_clicked", 0, 0 };
    static const QUMethod slot_143 = {"pushButton59_7_clicked", 0, 0 };
    static const QUMethod slot_144 = {"pushButton2_clicked", 0, 0 };
    static const QUMethod slot_145 = {"evaluateNow", 0, 0 };
    static const QUMethod slot_146 = {"pushButton82_clicked", 0, 0 };
    static const QUParameter param_slot_147[] = {
	{ "w", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_147 = {"widgetStack7_aboutToShow", 1, param_slot_147 };
    static const QUMethod slot_148 = {"radioButton20_clicked", 0, 0 };
    static const QUMethod slot_149 = {"pushButton4_clicked", 0, 0 };
    static const QUMethod slot_150 = {"pushButton81_clicked", 0, 0 };
    static const QUMethod slot_151 = {"pushButton82_2_clicked", 0, 0 };
    static const QUMethod slot_152 = {"pushButton83_clicked", 0, 0 };
    static const QUParameter param_slot_153[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_153 = {"lineEdit17_textChanged", 1, param_slot_153 };
    static const QUMethod slot_154 = {"lineEdit17_2_returnPressed", 0, 0 };
    static const QUMethod slot_155 = {"lineEdit17_returnPressed", 0, 0 };
    static const QUParameter param_slot_156[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_156 = {"lineEdit17_2_textChanged", 1, param_slot_156 };
    static const QUMethod slot_157 = {"pushButton163_clicked", 0, 0 };
    static const QUMethod slot_158 = {"pushButton75_clicked", 0, 0 };
    static const QUMethod slot_159 = {"radioButton21_clicked", 0, 0 };
    static const QUMethod slot_160 = {"radioButton22_clicked", 0, 0 };
    static const QUMethod slot_161 = {"pushButton74_clicked", 0, 0 };
    static const QUParameter param_slot_162[] = {
	{ "name", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_162 = {"tabWidget2_selected", 1, param_slot_162 };
    static const QUMethod slot_163 = {"timerStateShow", 0, 0 };
    static const QUMethod slot_164 = {"pushButton75_2_clicked", 0, 0 };
    static const QUParameter param_slot_165[] = {
	{ "state", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_165 = {"checkBox8_stateChanged", 1, param_slot_165 };
    static const QUParameter param_slot_166[] = {
	{ "vs", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_166 = {"lineEdit61_textChanged", 1, param_slot_166 };
    static const QUParameter param_slot_167[] = {
	{ "vs", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_167 = {"lineEdit62_textChanged", 1, param_slot_167 };
    static const QUParameter param_slot_168[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_168 = {"radioButton21_2_toggled", 1, param_slot_168 };
    static const QUParameter param_slot_169[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_169 = {"radioButton22_2_toggled", 1, param_slot_169 };
    static const QUMethod slot_170 = {"checkBox9_clicked", 0, 0 };
    static const QUMethod slot_171 = {"pushButton74_2_clicked", 0, 0 };
    static const QUParameter param_slot_172[] = {
	{ "state", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_172 = {"predictionRadio_stateChanged", 1, param_slot_172 };
    static const QUMethod slot_173 = {"initEntryForm", 0, 0 };
    static const QUParameter param_slot_174[] = {
	{ "state", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_174 = {"radioButton28_stateChanged", 1, param_slot_174 };
    static const QUParameter param_slot_175[] = {
	{ "state", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_175 = {"radioButton27_stateChanged", 1, param_slot_175 };
    static const QUMethod slot_176 = {"openSession_clicked", 0, 0 };
    static const QUMethod slot_177 = {"setSessionVariableAndStart", 0, 0 };
    static const QUParameter param_slot_178[] = {
	{ "state", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_178 = {"radioButton33_stateChanged", 1, param_slot_178 };
    static const QUParameter param_slot_179[] = {
	{ "state", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_179 = {"radioButton34_stateChanged", 1, param_slot_179 };
    static const QUParameter param_slot_180[] = {
	{ "state", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_180 = {"radioButton29_stateChanged", 1, param_slot_180 };
    static const QUMethod slot_181 = {"pushButton75_3_clicked", 0, 0 };
    static const QUParameter param_slot_182[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::Out }
    };
    static const QUMethod slot_182 = {"updateFolderPathToFileMg", 1, param_slot_182 };
    static const QUMethod slot_183 = {"pushButton77_clicked", 0, 0 };
    static const QUMethod slot_184 = {"pushButton78_clicked", 0, 0 };
    static const QUMethod slot_185 = {"pushButton96_clicked", 0, 0 };
    static const QUMethod slot_186 = {"radioButton33_clicked", 0, 0 };
    static const QUMethod slot_187 = {"radioButton34_clicked", 0, 0 };
    static const QUMethod slot_188 = {"radioButton27_clicked", 0, 0 };
    static const QUMethod slot_189 = {"radioButton29_clicked", 0, 0 };
    static const QUParameter param_slot_190[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_190 = {"radioButton27_toggled", 1, param_slot_190 };
    static const QUMethod slot_191 = {"pushButton76_3_clicked", 0, 0 };
    static const QUMethod slot_192 = {"pushButton74_2_2_released", 0, 0 };
    static const QUMethod slot_193 = {"pushButton75_2_2_clicked", 0, 0 };
    static const QUMethod slot_194 = {"pushButton75_4_clicked", 0, 0 };
    static const QUParameter param_slot_195[] = {
	{ "state", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_195 = {"checkBox8_2_stateChanged", 1, param_slot_195 };
    static const QUParameter param_slot_196[] = {
	{ "n", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_196 = {"widgetStack6_aboutToShow", 1, param_slot_196 };
    static const QUParameter param_slot_197[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_197 = {"radioButton21_2_2_toggled", 1, param_slot_197 };
    static const QUParameter param_slot_198[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_198 = {"radioButton22_2_2_toggled", 1, param_slot_198 };
    static const QUMethod slot_199 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "apply()", &slot_0, QMetaData::Public },
	{ "initializeFields()", &slot_1, QMetaData::Public },
	{ "non_interactive_rstat_call()", &slot_2, QMetaData::Public },
	{ "non_interactive_pval_call()", &slot_3, QMetaData::Public },
	{ "InitializeApplication()", &slot_4, QMetaData::Public },
	{ "Initialize_Namespace()", &slot_5, QMetaData::Public },
	{ "browseFile_clicked()", &slot_6, QMetaData::Public },
	{ "acceptPath_Ready_for_Computation()", &slot_7, QMetaData::Public },
	{ "updateStatusView()", &slot_8, QMetaData::Public },
	{ "setGUIState()", &slot_9, QMetaData::Public },
	{ "nextForm_NI()", &slot_10, QMetaData::Public },
	{ "previousForm_NI()", &slot_11, QMetaData::Public },
	{ "linkResults(int,int)", &slot_12, QMetaData::Public },
	{ "openFile(const char*)", &slot_13, QMetaData::Public },
	{ "sequenceFileName_textChanged(const QString&)", &slot_14, QMetaData::Public },
	{ "computeOrfNowPushButton_clicked()", &slot_15, QMetaData::Public },
	{ "goToNextPageORF()", &slot_16, QMetaData::Public },
	{ "goToPreviousPageORF()", &slot_17, QMetaData::Public },
	{ "goToPreviousPageRANDOM()", &slot_18, QMetaData::Public },
	{ "goToNextPageRANDOM()", &slot_19, QMetaData::Public },
	{ "goToNextPageRStatistics()", &slot_20, QMetaData::Public },
	{ "goToPreviousPageRStatistics()", &slot_21, QMetaData::Public },
	{ "goToNextPagePValue()", &slot_22, QMetaData::Public },
	{ "goToPreviousPagePValue()", &slot_23, QMetaData::Public },
	{ "pushButton14_clicked()", &slot_24, QMetaData::Public },
	{ "initialize_max_min_fields()", &slot_25, QMetaData::Public },
	{ "pushButton15_clicked()", &slot_26, QMetaData::Public },
	{ "pushButton20_clicked()", &slot_27, QMetaData::Public },
	{ "pushButton12_clicked()", &slot_28, QMetaData::Public },
	{ "orfRadio_clicked()", &slot_29, QMetaData::Public },
	{ "predictionRadio_clicked()", &slot_30, QMetaData::Public },
	{ "pushButton16_3_clicked()", &slot_31, QMetaData::Public },
	{ "pushButton16_2_clicked()", &slot_32, QMetaData::Public },
	{ "pushButton16_clicked()", &slot_33, QMetaData::Public },
	{ "pushButton19_clicked()", &slot_34, QMetaData::Public },
	{ "radioButton7_clicked()", &slot_35, QMetaData::Public },
	{ "radioButton8_clicked()", &slot_36, QMetaData::Public },
	{ "radioButton9_clicked()", &slot_37, QMetaData::Public },
	{ "radioButton10_clicked()", &slot_38, QMetaData::Public },
	{ "checkBox2_toggled(bool)", &slot_39, QMetaData::Public },
	{ "pushButton15_released()", &slot_40, QMetaData::Public },
	{ "pushButton26_clicked()", &slot_41, QMetaData::Public },
	{ "widgetStack_aboutToShow(QWidget*)", &slot_42, QMetaData::Public },
	{ "lineEdit3_textChanged(const QString&)", &slot_43, QMetaData::Public },
	{ "enablePusButton14()", &slot_44, QMetaData::Public },
	{ "lineEdit4_textChanged(const QString&)", &slot_45, QMetaData::Public },
	{ "pushButton27_clicked()", &slot_46, QMetaData::Public },
	{ "pushButton28_clicked()", &slot_47, QMetaData::Public },
	{ "pushButton25_pressed()", &slot_48, QMetaData::Public },
	{ "pushButton3_clicked()", &slot_49, QMetaData::Public },
	{ "pushButton16_4_released()", &slot_50, QMetaData::Public },
	{ "pushButton18_released()", &slot_51, QMetaData::Public },
	{ "pushButton19_2_released()", &slot_52, QMetaData::Public },
	{ "pushButton20_2_clicked()", &slot_53, QMetaData::Public },
	{ "pushButton21_clicked()", &slot_54, QMetaData::Public },
	{ "pushButton29_clicked()", &slot_55, QMetaData::Public },
	{ "pushButton29_2_clicked()", &slot_56, QMetaData::Public },
	{ "pushButton29_4_clicked()", &slot_57, QMetaData::Public },
	{ "nearest_neighbour_default(int)", &slot_58, QMetaData::Public },
	{ "nearest_neighbour_default_1(int,int,int)", &slot_59, QMetaData::Public },
	{ "pushButton27_2_5_clicked()", &slot_60, QMetaData::Public },
	{ "pushButton27_2_6_clicked()", &slot_61, QMetaData::Public },
	{ "pushButton27_2_7_clicked()", &slot_62, QMetaData::Public },
	{ "pushButton27_2_8_clicked()", &slot_63, QMetaData::Public },
	{ "pushButton29_5_clicked()", &slot_64, QMetaData::Public },
	{ "pushButton29_2_2_clicked()", &slot_65, QMetaData::Public },
	{ "pushButton29_4_2_clicked()", &slot_66, QMetaData::Public },
	{ "pushButton27_2_clicked()", &slot_67, QMetaData::Public },
	{ "pushButton27_2_2_clicked()", &slot_68, QMetaData::Public },
	{ "pushButton27_2_3_clicked()", &slot_69, QMetaData::Public },
	{ "pushButton27_2_4_clicked()", &slot_70, QMetaData::Public },
	{ "tabWidget2_currentChanged(QWidget*)", &slot_71, QMetaData::Public },
	{ "pushButton35_clicked()", &slot_72, QMetaData::Public },
	{ "checkBox3_clicked()", &slot_73, QMetaData::Public },
	{ "checkBox3_2_clicked()", &slot_74, QMetaData::Public },
	{ "pushButton45_clicked()", &slot_75, QMetaData::Public },
	{ "directoryChangedWarning()", &slot_76, QMetaData::Public },
	{ "pushButton35_2_clicked()", &slot_77, QMetaData::Public },
	{ "pushButton35_3_clicked()", &slot_78, QMetaData::Public },
	{ "widgetStack5_aboutToShow(int)", &slot_79, QMetaData::Public },
	{ "pushButton29_3_pressed()", &slot_80, QMetaData::Public },
	{ "pushButton29_3_released()", &slot_81, QMetaData::Public },
	{ "pushButton35_4_clicked()", &slot_82, QMetaData::Public },
	{ "pushButton27_2_5_2_clicked()", &slot_83, QMetaData::Public },
	{ "pushButton27_2_5_2_2_clicked()", &slot_84, QMetaData::Public },
	{ "pushButton27_2_5_2_3_clicked()", &slot_85, QMetaData::Public },
	{ "pushButton27_2_5_2_4_clicked()", &slot_86, QMetaData::Public },
	{ "pushButton35_5_clicked()", &slot_87, QMetaData::Public },
	{ "pushButton45_2_clicked()", &slot_88, QMetaData::Public },
	{ "pushButton35_6_clicked()", &slot_89, QMetaData::Public },
	{ "pushButton64_clicked()", &slot_90, QMetaData::Public },
	{ "pushButton27_2_2_2_clicked()", &slot_91, QMetaData::Public },
	{ "radioButton9_2_clicked()", &slot_92, QMetaData::Public },
	{ "radioButton8_2_clicked()", &slot_93, QMetaData::Public },
	{ "pushButton35_7_clicked()", &slot_94, QMetaData::Public },
	{ "pushButton35_8_clicked()", &slot_95, QMetaData::Public },
	{ "pushButton27_2_4_2_released()", &slot_96, QMetaData::Public },
	{ "pushButton27_2_4_2_2_released()", &slot_97, QMetaData::Public },
	{ "pushButton29_3_2_pressed()", &slot_98, QMetaData::Public },
	{ "pushButton29_3_2_released()", &slot_99, QMetaData::Public },
	{ "resultRadio_clicked()", &slot_100, QMetaData::Public },
	{ "newSlot()", &slot_101, QMetaData::Public },
	{ "pushButton50_clicked()", &slot_102, QMetaData::Public },
	{ "pushButton50_2_clicked()", &slot_103, QMetaData::Public },
	{ "pushButton50_3_clicked()", &slot_104, QMetaData::Public },
	{ "pushButton50_2_4_clicked()", &slot_105, QMetaData::Public },
	{ "closeSession_clicked()", &slot_106, QMetaData::Public },
	{ "pushButton59_clicked()", &slot_107, QMetaData::Public },
	{ "pushButton59_2_clicked()", &slot_108, QMetaData::Public },
	{ "pushButton59_2_2_released()", &slot_109, QMetaData::Public },
	{ "pushButton59_2_2_pressed()", &slot_110, QMetaData::Public },
	{ "pushButton59_2_3_clicked()", &slot_111, QMetaData::Public },
	{ "pushButton59_6_clicked()", &slot_112, QMetaData::Public },
	{ "pushButton59_5_released()", &slot_113, QMetaData::Public },
	{ "pushButton59_5_pressed()", &slot_114, QMetaData::Public },
	{ "pushButton59_4_clicked()", &slot_115, QMetaData::Public },
	{ "pushButton59_3_clicked()", &slot_116, QMetaData::Public },
	{ "radioButton11_clicked()", &slot_117, QMetaData::Public },
	{ "radioButton10_2_clicked()", &slot_118, QMetaData::Public },
	{ "radioButton10_2_2_clicked()", &slot_119, QMetaData::Public },
	{ "radioButton11_2_clicked()", &slot_120, QMetaData::Public },
	{ "radioButton10_2_2_2_clicked()", &slot_121, QMetaData::Public },
	{ "radioButton11_2_2_clicked()", &slot_122, QMetaData::Public },
	{ "pushButton29_4_3_clicked()", &slot_123, QMetaData::Public },
	{ "pushButton59_2_3_2_clicked()", &slot_124, QMetaData::Public },
	{ "pushButton69_clicked()", &slot_125, QMetaData::Public },
	{ "pushButton29_5_2_clicked()", &slot_126, QMetaData::Public },
	{ "pushButton69_2_clicked()", &slot_127, QMetaData::Public },
	{ "pushButton71_clicked()", &slot_128, QMetaData::Public },
	{ "pushButton71_2_clicked()", &slot_129, QMetaData::Public },
	{ "pushButton25_clicked()", &slot_130, QMetaData::Public },
	{ "checkBox4_stateChanged(int)", &slot_131, QMetaData::Public },
	{ "pushButton72_clicked()", &slot_132, QMetaData::Public },
	{ "pushButton76_clicked()", &slot_133, QMetaData::Public },
	{ "lineEdit8_textChanged()", &slot_134, QMetaData::Public },
	{ "lineEdit9_textChanged()", &slot_135, QMetaData::Public },
	{ "lineEdit8_3_textChanged()", &slot_136, QMetaData::Public },
	{ "lineEdit9_3_textChanged()", &slot_137, QMetaData::Public },
	{ "lineEdit8_2_textChanged()", &slot_138, QMetaData::Public },
	{ "lineEdit9_2_textChanged()", &slot_139, QMetaData::Public },
	{ "lineEdit8_3_2_textChanged()", &slot_140, QMetaData::Public },
	{ "lineEdit9_3_2_textChanged()", &slot_141, QMetaData::Public },
	{ "pushButton76_2_clicked()", &slot_142, QMetaData::Public },
	{ "pushButton59_7_clicked()", &slot_143, QMetaData::Public },
	{ "pushButton2_clicked()", &slot_144, QMetaData::Public },
	{ "evaluateNow()", &slot_145, QMetaData::Public },
	{ "pushButton82_clicked()", &slot_146, QMetaData::Public },
	{ "widgetStack7_aboutToShow(int)", &slot_147, QMetaData::Public },
	{ "radioButton20_clicked()", &slot_148, QMetaData::Public },
	{ "pushButton4_clicked()", &slot_149, QMetaData::Public },
	{ "pushButton81_clicked()", &slot_150, QMetaData::Public },
	{ "pushButton82_2_clicked()", &slot_151, QMetaData::Public },
	{ "pushButton83_clicked()", &slot_152, QMetaData::Public },
	{ "lineEdit17_textChanged(const QString&)", &slot_153, QMetaData::Public },
	{ "lineEdit17_2_returnPressed()", &slot_154, QMetaData::Public },
	{ "lineEdit17_returnPressed()", &slot_155, QMetaData::Public },
	{ "lineEdit17_2_textChanged(const QString&)", &slot_156, QMetaData::Public },
	{ "pushButton163_clicked()", &slot_157, QMetaData::Public },
	{ "pushButton75_clicked()", &slot_158, QMetaData::Public },
	{ "radioButton21_clicked()", &slot_159, QMetaData::Public },
	{ "radioButton22_clicked()", &slot_160, QMetaData::Public },
	{ "pushButton74_clicked()", &slot_161, QMetaData::Public },
	{ "tabWidget2_selected(const QString&)", &slot_162, QMetaData::Public },
	{ "timerStateShow()", &slot_163, QMetaData::Public },
	{ "pushButton75_2_clicked()", &slot_164, QMetaData::Public },
	{ "checkBox8_stateChanged(int)", &slot_165, QMetaData::Public },
	{ "lineEdit61_textChanged(const QString&)", &slot_166, QMetaData::Public },
	{ "lineEdit62_textChanged(const QString&)", &slot_167, QMetaData::Public },
	{ "radioButton21_2_toggled(bool)", &slot_168, QMetaData::Public },
	{ "radioButton22_2_toggled(bool)", &slot_169, QMetaData::Public },
	{ "checkBox9_clicked()", &slot_170, QMetaData::Public },
	{ "pushButton74_2_clicked()", &slot_171, QMetaData::Public },
	{ "predictionRadio_stateChanged(int)", &slot_172, QMetaData::Public },
	{ "initEntryForm()", &slot_173, QMetaData::Public },
	{ "radioButton28_stateChanged(int)", &slot_174, QMetaData::Public },
	{ "radioButton27_stateChanged(int)", &slot_175, QMetaData::Public },
	{ "openSession_clicked()", &slot_176, QMetaData::Public },
	{ "setSessionVariableAndStart()", &slot_177, QMetaData::Public },
	{ "radioButton33_stateChanged(int)", &slot_178, QMetaData::Public },
	{ "radioButton34_stateChanged(int)", &slot_179, QMetaData::Public },
	{ "radioButton29_stateChanged(int)", &slot_180, QMetaData::Public },
	{ "pushButton75_3_clicked()", &slot_181, QMetaData::Public },
	{ "updateFolderPathToFileMg()", &slot_182, QMetaData::Public },
	{ "pushButton77_clicked()", &slot_183, QMetaData::Public },
	{ "pushButton78_clicked()", &slot_184, QMetaData::Public },
	{ "pushButton96_clicked()", &slot_185, QMetaData::Public },
	{ "radioButton33_clicked()", &slot_186, QMetaData::Public },
	{ "radioButton34_clicked()", &slot_187, QMetaData::Public },
	{ "radioButton27_clicked()", &slot_188, QMetaData::Public },
	{ "radioButton29_clicked()", &slot_189, QMetaData::Public },
	{ "radioButton27_toggled(bool)", &slot_190, QMetaData::Public },
	{ "pushButton76_3_clicked()", &slot_191, QMetaData::Public },
	{ "pushButton74_2_2_released()", &slot_192, QMetaData::Public },
	{ "pushButton75_2_2_clicked()", &slot_193, QMetaData::Public },
	{ "pushButton75_4_clicked()", &slot_194, QMetaData::Public },
	{ "checkBox8_2_stateChanged(int)", &slot_195, QMetaData::Public },
	{ "widgetStack6_aboutToShow(int)", &slot_196, QMetaData::Public },
	{ "radioButton21_2_2_toggled(bool)", &slot_197, QMetaData::Public },
	{ "radioButton22_2_2_toggled(bool)", &slot_198, QMetaData::Public },
	{ "languageChange()", &slot_199, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"Form1", parentObject,
	slot_tbl, 200,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_Form1.setMetaObject( metaObj );
    return metaObj;
}

void* Form1::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "Form1" ) )
	return this;
    return QFrame::qt_cast( clname );
}

bool Form1::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: apply(); break;
    case 1: initializeFields(); break;
    case 2: non_interactive_rstat_call(); break;
    case 3: non_interactive_pval_call(); break;
    case 4: InitializeApplication(); break;
    case 5: Initialize_Namespace(); break;
    case 6: browseFile_clicked(); break;
    case 7: acceptPath_Ready_for_Computation(); break;
    case 8: updateStatusView(); break;
    case 9: setGUIState(); break;
    case 10: nextForm_NI(); break;
    case 11: previousForm_NI(); break;
    case 12: linkResults((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 13: openFile((const char*)static_QUType_charstar.get(_o+1)); break;
    case 14: sequenceFileName_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 15: computeOrfNowPushButton_clicked(); break;
    case 16: goToNextPageORF(); break;
    case 17: goToPreviousPageORF(); break;
    case 18: goToPreviousPageRANDOM(); break;
    case 19: goToNextPageRANDOM(); break;
    case 20: goToNextPageRStatistics(); break;
    case 21: goToPreviousPageRStatistics(); break;
    case 22: goToNextPagePValue(); break;
    case 23: goToPreviousPagePValue(); break;
    case 24: pushButton14_clicked(); break;
    case 25: initialize_max_min_fields(); break;
    case 26: pushButton15_clicked(); break;
    case 27: pushButton20_clicked(); break;
    case 28: pushButton12_clicked(); break;
    case 29: orfRadio_clicked(); break;
    case 30: predictionRadio_clicked(); break;
    case 31: pushButton16_3_clicked(); break;
    case 32: pushButton16_2_clicked(); break;
    case 33: pushButton16_clicked(); break;
    case 34: pushButton19_clicked(); break;
    case 35: radioButton7_clicked(); break;
    case 36: radioButton8_clicked(); break;
    case 37: radioButton9_clicked(); break;
    case 38: radioButton10_clicked(); break;
    case 39: checkBox2_toggled((bool)static_QUType_bool.get(_o+1)); break;
    case 40: pushButton15_released(); break;
    case 41: pushButton26_clicked(); break;
    case 42: widgetStack_aboutToShow((QWidget*)static_QUType_ptr.get(_o+1)); break;
    case 43: lineEdit3_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 44: enablePusButton14(); break;
    case 45: lineEdit4_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 46: pushButton27_clicked(); break;
    case 47: pushButton28_clicked(); break;
    case 48: pushButton25_pressed(); break;
    case 49: pushButton3_clicked(); break;
    case 50: pushButton16_4_released(); break;
    case 51: pushButton18_released(); break;
    case 52: pushButton19_2_released(); break;
    case 53: pushButton20_2_clicked(); break;
    case 54: pushButton21_clicked(); break;
    case 55: pushButton29_clicked(); break;
    case 56: pushButton29_2_clicked(); break;
    case 57: pushButton29_4_clicked(); break;
    case 58: nearest_neighbour_default((int)static_QUType_int.get(_o+1)); break;
    case 59: nearest_neighbour_default_1((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3)); break;
    case 60: pushButton27_2_5_clicked(); break;
    case 61: pushButton27_2_6_clicked(); break;
    case 62: pushButton27_2_7_clicked(); break;
    case 63: pushButton27_2_8_clicked(); break;
    case 64: pushButton29_5_clicked(); break;
    case 65: pushButton29_2_2_clicked(); break;
    case 66: pushButton29_4_2_clicked(); break;
    case 67: pushButton27_2_clicked(); break;
    case 68: pushButton27_2_2_clicked(); break;
    case 69: pushButton27_2_3_clicked(); break;
    case 70: pushButton27_2_4_clicked(); break;
    case 71: tabWidget2_currentChanged((QWidget*)static_QUType_ptr.get(_o+1)); break;
    case 72: pushButton35_clicked(); break;
    case 73: checkBox3_clicked(); break;
    case 74: checkBox3_2_clicked(); break;
    case 75: pushButton45_clicked(); break;
    case 76: directoryChangedWarning(); break;
    case 77: pushButton35_2_clicked(); break;
    case 78: pushButton35_3_clicked(); break;
    case 79: widgetStack5_aboutToShow((int)static_QUType_int.get(_o+1)); break;
    case 80: pushButton29_3_pressed(); break;
    case 81: pushButton29_3_released(); break;
    case 82: pushButton35_4_clicked(); break;
    case 83: pushButton27_2_5_2_clicked(); break;
    case 84: pushButton27_2_5_2_2_clicked(); break;
    case 85: pushButton27_2_5_2_3_clicked(); break;
    case 86: pushButton27_2_5_2_4_clicked(); break;
    case 87: pushButton35_5_clicked(); break;
    case 88: pushButton45_2_clicked(); break;
    case 89: pushButton35_6_clicked(); break;
    case 90: pushButton64_clicked(); break;
    case 91: pushButton27_2_2_2_clicked(); break;
    case 92: radioButton9_2_clicked(); break;
    case 93: radioButton8_2_clicked(); break;
    case 94: pushButton35_7_clicked(); break;
    case 95: pushButton35_8_clicked(); break;
    case 96: pushButton27_2_4_2_released(); break;
    case 97: pushButton27_2_4_2_2_released(); break;
    case 98: pushButton29_3_2_pressed(); break;
    case 99: pushButton29_3_2_released(); break;
    case 100: resultRadio_clicked(); break;
    case 101: newSlot(); break;
    case 102: pushButton50_clicked(); break;
    case 103: pushButton50_2_clicked(); break;
    case 104: pushButton50_3_clicked(); break;
    case 105: pushButton50_2_4_clicked(); break;
    case 106: closeSession_clicked(); break;
    case 107: pushButton59_clicked(); break;
    case 108: pushButton59_2_clicked(); break;
    case 109: pushButton59_2_2_released(); break;
    case 110: pushButton59_2_2_pressed(); break;
    case 111: pushButton59_2_3_clicked(); break;
    case 112: pushButton59_6_clicked(); break;
    case 113: pushButton59_5_released(); break;
    case 114: pushButton59_5_pressed(); break;
    case 115: pushButton59_4_clicked(); break;
    case 116: pushButton59_3_clicked(); break;
    case 117: radioButton11_clicked(); break;
    case 118: radioButton10_2_clicked(); break;
    case 119: radioButton10_2_2_clicked(); break;
    case 120: radioButton11_2_clicked(); break;
    case 121: radioButton10_2_2_2_clicked(); break;
    case 122: radioButton11_2_2_clicked(); break;
    case 123: pushButton29_4_3_clicked(); break;
    case 124: pushButton59_2_3_2_clicked(); break;
    case 125: pushButton69_clicked(); break;
    case 126: pushButton29_5_2_clicked(); break;
    case 127: pushButton69_2_clicked(); break;
    case 128: pushButton71_clicked(); break;
    case 129: pushButton71_2_clicked(); break;
    case 130: pushButton25_clicked(); break;
    case 131: checkBox4_stateChanged((int)static_QUType_int.get(_o+1)); break;
    case 132: pushButton72_clicked(); break;
    case 133: pushButton76_clicked(); break;
    case 134: lineEdit8_textChanged(); break;
    case 135: lineEdit9_textChanged(); break;
    case 136: lineEdit8_3_textChanged(); break;
    case 137: lineEdit9_3_textChanged(); break;
    case 138: lineEdit8_2_textChanged(); break;
    case 139: lineEdit9_2_textChanged(); break;
    case 140: lineEdit8_3_2_textChanged(); break;
    case 141: lineEdit9_3_2_textChanged(); break;
    case 142: pushButton76_2_clicked(); break;
    case 143: pushButton59_7_clicked(); break;
    case 144: pushButton2_clicked(); break;
    case 145: evaluateNow(); break;
    case 146: pushButton82_clicked(); break;
    case 147: widgetStack7_aboutToShow((int)static_QUType_int.get(_o+1)); break;
    case 148: radioButton20_clicked(); break;
    case 149: pushButton4_clicked(); break;
    case 150: pushButton81_clicked(); break;
    case 151: pushButton82_2_clicked(); break;
    case 152: pushButton83_clicked(); break;
    case 153: lineEdit17_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 154: lineEdit17_2_returnPressed(); break;
    case 155: lineEdit17_returnPressed(); break;
    case 156: lineEdit17_2_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 157: pushButton163_clicked(); break;
    case 158: pushButton75_clicked(); break;
    case 159: radioButton21_clicked(); break;
    case 160: radioButton22_clicked(); break;
    case 161: pushButton74_clicked(); break;
    case 162: tabWidget2_selected((const QString&)static_QUType_QString.get(_o+1)); break;
    case 163: timerStateShow(); break;
    case 164: pushButton75_2_clicked(); break;
    case 165: checkBox8_stateChanged((int)static_QUType_int.get(_o+1)); break;
    case 166: lineEdit61_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 167: lineEdit62_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 168: radioButton21_2_toggled((bool)static_QUType_bool.get(_o+1)); break;
    case 169: radioButton22_2_toggled((bool)static_QUType_bool.get(_o+1)); break;
    case 170: checkBox9_clicked(); break;
    case 171: pushButton74_2_clicked(); break;
    case 172: predictionRadio_stateChanged((int)static_QUType_int.get(_o+1)); break;
    case 173: initEntryForm(); break;
    case 174: radioButton28_stateChanged((int)static_QUType_int.get(_o+1)); break;
    case 175: radioButton27_stateChanged((int)static_QUType_int.get(_o+1)); break;
    case 176: openSession_clicked(); break;
    case 177: setSessionVariableAndStart(); break;
    case 178: radioButton33_stateChanged((int)static_QUType_int.get(_o+1)); break;
    case 179: radioButton34_stateChanged((int)static_QUType_int.get(_o+1)); break;
    case 180: radioButton29_stateChanged((int)static_QUType_int.get(_o+1)); break;
    case 181: pushButton75_3_clicked(); break;
    case 182: static_QUType_bool.set(_o,updateFolderPathToFileMg()); break;
    case 183: pushButton77_clicked(); break;
    case 184: pushButton78_clicked(); break;
    case 185: pushButton96_clicked(); break;
    case 186: radioButton33_clicked(); break;
    case 187: radioButton34_clicked(); break;
    case 188: radioButton27_clicked(); break;
    case 189: radioButton29_clicked(); break;
    case 190: radioButton27_toggled((bool)static_QUType_bool.get(_o+1)); break;
    case 191: pushButton76_3_clicked(); break;
    case 192: pushButton74_2_2_released(); break;
    case 193: pushButton75_2_2_clicked(); break;
    case 194: pushButton75_4_clicked(); break;
    case 195: checkBox8_2_stateChanged((int)static_QUType_int.get(_o+1)); break;
    case 196: widgetStack6_aboutToShow((int)static_QUType_int.get(_o+1)); break;
    case 197: radioButton21_2_2_toggled((bool)static_QUType_bool.get(_o+1)); break;
    case 198: radioButton22_2_2_toggled((bool)static_QUType_bool.get(_o+1)); break;
    case 199: languageChange(); break;
    default:
	return QFrame::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool Form1::qt_emit( int _id, QUObject* _o )
{
    return QFrame::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool Form1::qt_property( int id, int f, QVariant* v)
{
    return QFrame::qt_property( id, f, v);
}

bool Form1::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
