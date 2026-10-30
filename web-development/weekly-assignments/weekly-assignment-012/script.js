const API_CHAVE="714cc7b342e8604c18bdeeef1a55d25d";
const BASE_URL="https://api.themoviedb.org/3";

async function getMovies(){
    try{
        const searchInput=document.getElementById("busca_filme").value;
        const response = await fetch(`${BASE_URL}/search/movie?api_key=${API_CHAVE}&query=${searchInput}`);
        if(!response.ok){
            throw new Error("Erro ao buscar filmes");
        }
        const data= await response.json();
        displayMovies(data.results);
    }   
    catch(error){
        console.error("Error fetching movies:", error);
    }
}

function displayMovies(movies){
    const moviesContainer=document.getElementById("movie-list");
    movies.forEach(movie => {
        const movieElement=document.createElement("div");
        movieElement.classList.add("movie");
        movieElement.innerHTML = `
            <img src="https://image.tmdb.org/t/p/w500${movie.poster_path}" alt="${movie.title}">
            <h3>${movie.title}<h3>
            <p>${movie.overview}</p>
        `;
        moviesContainer.appendChild(movieElement);
    });
}