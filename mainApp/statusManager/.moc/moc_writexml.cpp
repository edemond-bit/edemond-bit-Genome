/****************************************************************************
** writexml meta object code from reading C++ file 'writexml.h'
**
** Created: Sun Sep 30 21:48:38 2007
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.3   edited Aug 5 16:40 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../writexml.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *writexml::className() const
{
    return "writexml";
}

QMetaObject *writexml::metaObj = 0;
static QMetaObjectCleanUp cleanUp_writexml( "writexml", &writexml::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString writexml::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "writexml", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString writexml::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "writexml", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* writexml::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"writexml", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_writexml.setMetaObject( metaObj );
    return metaObj;
}

void* writexml::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "writexml" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool writexml::qt_invoke( int _id, QUObject* _o )
{
    return QDialog::qt_invoke(_id,_o);
}

bool writexml::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool writexml::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool writexml::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
