docker network create bddnet
docker volume create data_mdb

docker run \
	--name maria \
	--network=bddnet \
	-e MARIADB_ROOT_PASSWORD=secret \
	-v data_mdb:/var/lib/mysql \
	-d \
	-p 3309:3306 \
	mariadb:11.2

# options
# --rm: suppression conteneur après son arrêt
# -d: exécution en mode "detached"

	
	
