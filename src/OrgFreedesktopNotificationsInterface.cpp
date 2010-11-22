#include "OrgFreedesktopNotificationsInterface.h"

OrgFreedesktopNotificationsInterface::OrgFreedesktopNotificationsInterface(const QString & service,
																		   const QString & path,
																		   const QDBusConnection & connection,
																		   QObject * parent) :
	QDBusAbstractInterface(service, path, staticInterfaceName(), connection, parent)
{
}

OrgFreedesktopNotificationsInterface::~OrgFreedesktopNotificationsInterface()
{
}

QDBusPendingReply<QStringList> OrgFreedesktopNotificationsInterface::getCapabilities()
{
	return asyncCall("GetCapabilities");
}

QDBusPendingReply<quint32> OrgFreedesktopNotificationsInterface::notify(const QString & appName, quint32 replacesId,
																		const QString & appIcon,
																		const QString & summary, const QString & body,
																		const QStringList & actions,
																		const QVariantMap & hints,
																		qint32 timeout)
{
	return asyncCall("Notify", appName, replacesId, appIcon, summary, body, actions, hints, timeout);
}

QDBusPendingReply<> OrgFreedesktopNotificationsInterface::closeNotification(quint32 id)
{
	return asyncCall("CloseNotification", id);
}

QDBusPendingReply<QString, QString, QString> OrgFreedesktopNotificationsInterface::getServerInformation()
{
	return asyncCall("GetServerInformation");
}

