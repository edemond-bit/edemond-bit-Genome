/****************************************************************************
** RandomDialog meta object code from reading C++ file 'RandomDialog.h'
**
** Created: Sat Nov 27 12:06:46 2010
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.3   edited Aug 5 16:40 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "RandomDialog.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *RandomDialog::className() const
{
    return "RandomDialog";
}

QMetaObject *RandomDialog::metaObj = 0;
static QMetaObjectCleanUp cleanUp_RandomDialog( "RandomDialog", &RandomDialog::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString RandomDialog::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "RandomDialog", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString RandomDialog::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "RandomDialog", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* RandomDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"lineEdit2_textChanged", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"lineEdit3_textChanged", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"lineEdit1_textChanged", 1, param_slot_2 };
    static const QUMethod slot_3 = {"purtrub_value_default", 0, 0 };
    static const QUMethod slot_4 = {"buttonCreateRand_pressed", 0, 0 };
    static const QUMethod slot_5 = {"buttonCreateRand_released", 0, 0 };
    static const QUMethod slot_6 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "lineEdit2_textChanged(const QString&)", &slot_0, QMetaData::Public },
	{ "lineEdit3_textChanged(const QString&)", &slot_1, QMetaData::Public },
	{ "lineEdit1_textChanged(const QString&)", &slot_2, QMetaData::Public },
	{ "purtrub_value_default()", &slot_3, QMetaData::Public },
	{ "buttonCreateRand_pressed()", &slot_4, QMetaData::Public },
	{ "buttonCreateRand_released()", &slot_5, QMetaData::Public },
	{ "languageChange()", &slot_6, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"RandomDialog", parentObject,
	slot_tbl, 7,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_RandomDialog.setMetaObject( metaObj );
    return metaObj;
}

void* RandomDialog::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "RandomDialog" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool RandomDialog::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: lineEdit2_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: lineEdit3_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 2: lineEdit1_textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 3: purtrub_value_default(); break;
    case 4: buttonCreateRand_pressed(); break;
    case 5: buttonCreateRand_released(); break;
    case 6: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool RandomDialog::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool RandomDialog::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool RandomDialog::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
