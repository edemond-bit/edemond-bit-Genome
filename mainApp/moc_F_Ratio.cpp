/****************************************************************************
** F_Ratio meta object code from reading C++ file 'F_Ratio.h'
**
** Created: Sat Nov 27 12:06:40 2010
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.3   edited Aug 5 16:40 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "F_Ratio.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *F_Ratio::className() const
{
    return "F_Ratio";
}

QMetaObject *F_Ratio::metaObj = 0;
static QMetaObjectCleanUp cleanUp_F_Ratio( "F_Ratio", &F_Ratio::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString F_Ratio::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "F_Ratio", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString F_Ratio::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "F_Ratio", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* F_Ratio::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"initialize", 0, 0 };
    static const QUMethod slot_1 = {"radioButton21_clicked", 0, 0 };
    static const QUMethod slot_2 = {"radioButton22_clicked", 0, 0 };
    static const QUMethod slot_3 = {"buttonOk_pressed", 0, 0 };
    static const QUMethod slot_4 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "initialize()", &slot_0, QMetaData::Public },
	{ "radioButton21_clicked()", &slot_1, QMetaData::Public },
	{ "radioButton22_clicked()", &slot_2, QMetaData::Public },
	{ "buttonOk_pressed()", &slot_3, QMetaData::Public },
	{ "languageChange()", &slot_4, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"F_Ratio", parentObject,
	slot_tbl, 5,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_F_Ratio.setMetaObject( metaObj );
    return metaObj;
}

void* F_Ratio::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "F_Ratio" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool F_Ratio::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: initialize(); break;
    case 1: radioButton21_clicked(); break;
    case 2: radioButton22_clicked(); break;
    case 3: buttonOk_pressed(); break;
    case 4: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool F_Ratio::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool F_Ratio::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool F_Ratio::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
