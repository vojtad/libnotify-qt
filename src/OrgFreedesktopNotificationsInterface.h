#ifndef ORGFREEDESKTOPNOTIFICATIONSINTERFACE_H
#define ORGFREEDESKTOPNOTIFICATIONSINTERFACE_H

#include <QDBusAbstractInterface>
#include <QDBusPendingReply>

class OrgFreedesktopNotificationsInterface : public QDBusAbstractInterface
{
	Q_OBJECT

	public:
		OrgFreedesktopNotificationsInterface(const QString & service, const QString & path,
											 const QDBusConnection & connection, QObject * parent = 0);
		~OrgFreedesktopNotificationsInterface();

		static inline const char * staticInterfaceName()
		{
			return "org.freedesktop.Notifications";
		}

	public slots:
		QDBusPendingReply<QStringList> getCapabilities();
		QDBusPendingReply<quint32> notify(const QString & appName, quint32 replacesId, const QString & appIcon,
										  const QString & summary, const QString & body,
										  const QStringList & actions, const QVariantMap & hints,
										  qint32 timeout);
		QDBusPendingReply<> closeNotification(quint32 id);
		QDBusPendingReply<QString, QString, QString> getServerInformation();

	/*signals:
		void notificationClosed(quint32 id, quint32 reason);
		void actionInvoked(quint32 id, const QString & actionKey);*/
};

namespace org
{
	namespace freedesktop
	{
		typedef OrgFreedesktopNotificationsInterface Notifications;
	}
}

#endif // ORGFREEDESKTOPNOTIFICATIONSINTERFACE_H
