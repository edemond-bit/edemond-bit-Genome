/****************************************************************************
** Folder_creation meta object code from reading C++ file 'createDirectory.h'
**
** Created: Sat Nov 27 12:06:45 2010
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.3   edited Aug 5 16:40 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "createDirectory.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *Folder_creation::className() const
{
    return "Folder_creation";
}

QMetaObject *Folder_creation::metaObj = 0;
static QMetaObjectCleanUp cleanUp_Folder_creation( "Folder_creation", &Folder_creation::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString Folder_creation::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Folder_creation", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString Folder_creation::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Folder_creation", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* Folder_creation::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"buttonOk_clicked", 0, 0 };
    static const QUMethod slot_1 = {"reject", 0, 0 };
    static const QUMethod slot_2 = {"newSlot", 0, 0 };
    static const QUMethod slot_3 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "buttonOk_clicked()", &slot_0, QMetaData::Public },
	{ "reject()", &slot_1, QMetaData::Public },
	{ "newSlot()", &slot_2, QMetaData::Public },
	{ "languageChange()", &slot_3, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"Folder_creation", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_Folder_creation.setMetaObject( metaObj );
    return metaObj;
}

void* Folder_creation::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "Folder_creation" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool Folder_creation::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: buttonOk_clicked(); break;
    case 1: reject(); break;
    case 2: newSlot(); break;
    case 3: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool Folder_creation::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool Folder_creation::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool Folder_creation::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
