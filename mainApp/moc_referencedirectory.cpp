/****************************************************************************
** ReferenceDirectory meta object code from reading C++ file 'referencedirectory.h'
**
** Created: Sat Nov 27 12:06:44 2010
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.3   edited Aug 5 16:40 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "referencedirectory.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *ReferenceDirectory::className() const
{
    return "ReferenceDirectory";
}

QMetaObject *ReferenceDirectory::metaObj = 0;
static QMetaObjectCleanUp cleanUp_ReferenceDirectory( "ReferenceDirectory", &ReferenceDirectory::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString ReferenceDirectory::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ReferenceDirectory", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString ReferenceDirectory::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ReferenceDirectory", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* ReferenceDirectory::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "l", &static_QUType_ptr, "QLineEdit", QUParameter::In },
	{ "t", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"getDatabasePath", 2, param_slot_0 };
    static const QUMethod slot_1 = {"pushButton167_clicked", 0, 0 };
    static const QUMethod slot_2 = {"pushButton1_clicked", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ "resultName", &static_QUType_varptr, "\x03", QUParameter::In },
	{ "dirName", &static_QUType_varptr, "\x03", QUParameter::In }
    };
    static const QUMethod slot_3 = {"prepXML_FileList", 2, param_slot_3 };
    static const QUMethod slot_4 = {"pushButton167_2_clicked", 0, 0 };
    static const QUMethod slot_5 = {"pushButton167_3_clicked", 0, 0 };
    static const QUMethod slot_6 = {"pushButton170_clicked", 0, 0 };
    static const QUParameter param_slot_7[] = {
	{ "test", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"checkAndCreateXML", 1, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ "n", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"setOption", 1, param_slot_8 };
    static const QUMethod slot_9 = {"pushButton171_clicked", 0, 0 };
    static const QUParameter param_slot_10[] = {
	{ 0, &static_QUType_ptr, "QObject", QUParameter::In }
    };
    static const QUMethod slot_10 = {"ReferenceDirectory_destroyed", 1, param_slot_10 };
    static const QUMethod slot_11 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "getDatabasePath(QLineEdit*,QString)", &slot_0, QMetaData::Public },
	{ "pushButton167_clicked()", &slot_1, QMetaData::Public },
	{ "pushButton1_clicked()", &slot_2, QMetaData::Public },
	{ "prepXML_FileList(QString*,QString*)", &slot_3, QMetaData::Public },
	{ "pushButton167_2_clicked()", &slot_4, QMetaData::Public },
	{ "pushButton167_3_clicked()", &slot_5, QMetaData::Public },
	{ "pushButton170_clicked()", &slot_6, QMetaData::Public },
	{ "checkAndCreateXML(int)", &slot_7, QMetaData::Public },
	{ "setOption(int)", &slot_8, QMetaData::Public },
	{ "pushButton171_clicked()", &slot_9, QMetaData::Public },
	{ "ReferenceDirectory_destroyed(QObject*)", &slot_10, QMetaData::Public },
	{ "languageChange()", &slot_11, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"ReferenceDirectory", parentObject,
	slot_tbl, 12,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_ReferenceDirectory.setMetaObject( metaObj );
    return metaObj;
}

void* ReferenceDirectory::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "ReferenceDirectory" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool ReferenceDirectory::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: getDatabasePath((QLineEdit*)static_QUType_ptr.get(_o+1),(QString)static_QUType_QString.get(_o+2)); break;
    case 1: pushButton167_clicked(); break;
    case 2: pushButton1_clicked(); break;
    case 3: prepXML_FileList((QString*)static_QUType_varptr.get(_o+1),(QString*)static_QUType_varptr.get(_o+2)); break;
    case 4: pushButton167_2_clicked(); break;
    case 5: pushButton167_3_clicked(); break;
    case 6: pushButton170_clicked(); break;
    case 7: checkAndCreateXML((int)static_QUType_int.get(_o+1)); break;
    case 8: setOption((int)static_QUType_int.get(_o+1)); break;
    case 9: pushButton171_clicked(); break;
    case 10: ReferenceDirectory_destroyed((QObject*)static_QUType_ptr.get(_o+1)); break;
    case 11: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool ReferenceDirectory::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool ReferenceDirectory::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool ReferenceDirectory::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
