const API_CHAVE="714cc7b342e8604c18bdeeef1a55d25d";
const BASE_URL="https://api.themoviedb.org/3";

async function getMovies(){
    try{
        const response = await fetch(`${BASE_URL}/trending/movie/day?api_key=${API_CHAVE}`);
        if(!response.ok){
            throw new Error("Erro ao buscar filmes");
        }
        const data= await response.json();
        console.log(data);
        return data;
    }   
    catch(error){
        console.error("Error fetching movies:", error);
    }

}

async function getMovieDetails(movieId){
    try{
        const response=await fetch(`${BASE_URL}/movie/${movieId}?api_key=${API_CHAVE}`);
        if(!response.ok){
            throw new Error("Erro ao buscar detalhes do filme");
        }
        const data= await response.json();
        console.log(data);
        return data;
    }

    catch(error){
        console.error("Error fetching movie details:", error);
    }

}

function displayMovies(movies){
    const moviesContainer=document.getElementById("movie-list");
    movies.forEach(movie => {
        const movieElement=document.createElement("div");
        movieElement.classList.add("movie");
        /*criar inner html*/
        moviesContainer.appendChild(movieElement);
    });
}