docker network create bddnet
docker volume create mesdatas

docker run \
	--name bddserver8 \
	--network=bddnet \
	-e MYSQL_ROOT_PASSWORD=secret \
	-v mesdatas:/var/lib/mysql \
	-d \
	-p 3308:3306 \
	mysql:8.4 --mysql-native-password=ON

# options
# --rm: suppression conteneur après son arrêt
# -d: exécution en mode "detached"

	
	
