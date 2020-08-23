/****************************************************************************
** Omega_Peak_Inputs meta object code from reading C++ file 'Omega_Peak_Inputs.h'
**
** Created: Sat Nov 27 12:06:48 2010
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.3   edited Aug 5 16:40 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "Omega_Peak_Inputs.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *Omega_Peak_Inputs::className() const
{
    return "Omega_Peak_Inputs";
}

QMetaObject *Omega_Peak_Inputs::metaObj = 0;
static QMetaObjectCleanUp cleanUp_Omega_Peak_Inputs( "Omega_Peak_Inputs", &Omega_Peak_Inputs::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString Omega_Peak_Inputs::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Omega_Peak_Inputs", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString Omega_Peak_Inputs::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Omega_Peak_Inputs", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* Omega_Peak_Inputs::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"cmdOmegaNum_clicked", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ "Num", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"txtOmegaNum_textChanged", 1, param_slot_1 };
    static const QUMethod slot_2 = {"setOmega", 0, 0 };
    static const QUMethod slot_3 = {"resetOmega", 0, 0 };
    static const QUMethod slot_4 = {"setRStatistic", 0, 0 };
    static const QUMethod slot_5 = {"resetRStatistic", 0, 0 };
    static const QUParameter param_slot_6[] = {
	{ "Num", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"txtLClipFrom_textChanged", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ "Num", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"txtLClipTo_textChanged", 1, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ "Num", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"txtRClipFrom_textChanged", 1, param_slot_8 };
    static const QUParameter param_slot_9[] = {
	{ "Num", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_9 = {"txtRClipTo_textChanged", 1, param_slot_9 };
    static const QUParameter param_slot_10[] = {
	{ "Num", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_10 = {"txtPeakValue_textChanged", 1, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ "event", &static_QUType_ptr, "QCloseEvent", QUParameter::In }
    };
    static const QUMethod slot_11 = {"closeEvent", 1, param_slot_11 };
    static const QUParameter param_slot_12[] = {
	{ "Num", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_12 = {"txtInitOmega_textChanged", 1, param_slot_12 };
    static const QUParameter param_slot_13[] = {
	{ "Num", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_13 = {"txtEnd_textChanged", 1, param_slot_13 };
    static const QUParameter param_slot_14[] = {
	{ "Num", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_14 = {"txtWith_textChanged", 1, param_slot_14 };
    static const QUMethod slot_15 = {"cmdOK_clicked", 0, 0 };
    static const QUMethod slot_16 = {"cmdCancel_clicked", 0, 0 };
    static const QUParameter param_slot_17[] = {
	{ "Status", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_17 = {"ErrorSlot", 1, param_slot_17 };
    static const QUParameter param_slot_18[] = {
	{ "Msg", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_18 = {"FileErrorSlot", 1, param_slot_18 };
    static const QUParameter param_slot_19[] = {
	{ 0, &static_QUType_ptr, "QObject", QUParameter::In }
    };
    static const QUMethod slot_19 = {"Omega_Peak_Inputs_destroyed", 1, param_slot_19 };
    static const QUMethod slot_20 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "cmdOmegaNum_clicked()", &slot_0, QMetaData::Public },
	{ "txtOmegaNum_textChanged(const QString&)", &slot_1, QMetaData::Public },
	{ "setOmega()", &slot_2, QMetaData::Public },
	{ "resetOmega()", &slot_3, QMetaData::Public },
	{ "setRStatistic()", &slot_4, QMetaData::Public },
	{ "resetRStatistic()", &slot_5, QMetaData::Public },
	{ "txtLClipFrom_textChanged(const QString&)", &slot_6, QMetaData::Public },
	{ "txtLClipTo_textChanged(const QString&)", &slot_7, QMetaData::Public },
	{ "txtRClipFrom_textChanged(const QString&)", &slot_8, QMetaData::Public },
	{ "txtRClipTo_textChanged(const QString&)", &slot_9, QMetaData::Public },
	{ "txtPeakValue_textChanged(const QString&)", &slot_10, QMetaData::Public },
	{ "closeEvent(QCloseEvent*)", &slot_11, QMetaData::Public },
	{ "txtInitOmega_textChanged(const QString&)", &slot_12, QMetaData::Public },
	{ "txtEnd_textChanged(const QString&)", &slot_13, QMetaData::Public },
	{ "txtWith_textChanged(const QString&)", &slot_14, QMetaData::Public },
	{ "cmdOK_clicked()", &slot_15, QMetaData::Public },
	{ "cmdCancel_clicked()", &slot_16, QMetaData::Public },
	{ "ErrorSlot(int)", &slot_17, QMetaData::Public },
	{ "FileErrorSlot(QString)", &slot_18, QMetaData::Public },
	{ "Omega_Peak_Inputs_destroyed(QObject*)", &slot_19, QMetaData::Public },
	{ "languageChange()", &slot_20, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"Omega_Peak_Inputs", parentObject,
	slot_tbl, 21,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_Omega_Peak_Inputs.setMetaObject( metaObj );
    return metaObj;
}

void* Omega_Peak_Inputs::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "Omega_Peak_Inputs" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool Omega_Peak_Inputs::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: cmdOmegaNum_clicked(); break;
    case 1: txtOmegaNum_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 2: setOmega(); break;
    case 3: resetOmega(); break;
    case 4: setRStatistic(); break;
    case 5: resetRStatistic(); break;
    case 6: txtLClipFrom_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 7: txtLClipTo_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 8: txtRClipFrom_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 9: txtRClipTo_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 10: txtPeakValue_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 11: closeEvent((QCloseEvent*)static_QUType_ptr.get(_o+1)); break;
    case 12: txtInitOmega_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 13: txtEnd_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 14: txtWith_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 15: cmdOK_clicked(); break;
    case 16: cmdCancel_clicked(); break;
    case 17: ErrorSlot((int)static_QUType_int.get(_o+1)); break;
    case 18: FileErrorSlot((QString)static_QUType_QString.get(_o+1)); break;
    case 19: Omega_Peak_Inputs_destroyed((QObject*)static_QUType_ptr.get(_o+1)); break;
    case 20: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool Omega_Peak_Inputs::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool Omega_Peak_Inputs::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool Omega_Peak_Inputs::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
