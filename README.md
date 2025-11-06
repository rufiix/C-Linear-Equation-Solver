# 🚀 Blazor Exercises - Kompleksowy Projekt Edukacyjny

## 📋 Spis treści

1. [Wprowadzenie](#-wprowadzenie)
2. [Architektura projektu](#-architektura-projektu)
3. [Technologie i narzędzia](#-technologie-i-narzędzia)
4. [Struktura rozwiązania](#-struktura-rozwiązania)
5. [Wymagania systemowe](#-wymagania-systemowe)
6. [Instalacja i konfiguracja](#-instalacja-i-konfiguracja)
7. [Uruchomienie aplikacji](#-uruchomienie-aplikacji)
8. [Funkcjonalności aplikacji](#-funkcjonalności-aplikacji)
9. [Szczegółowy opis komponentów](#-szczegółowy-opis-komponentów)
10. [Baza danych](#-baza-danych)
11. [API REST](#-api-rest)
12. [Tryby renderowania Blazor](#-tryby-renderowania-blazor)
13. [Rozwój i debugowanie](#-rozwój-i-debugowanie)
14. [Struktura folderów](#-struktura-folderów)
15. [Najczęstsze problemy](#-najczęstsze-problemy)
16. [Licencja](#-licencja)

---

## 🎯 Wprowadzenie

**Blazor Exercises** to kompletny, edukacyjny projekt demonstracyjny napisany w **ASP.NET Core 9.0** i **Blazor**, który prezentuje różne wzorce, techniki i możliwości frameworka Blazor. Projekt zawiera zarówno przykłady **Server-Side Rendering (SSR)**, jak i **WebAssembly (WASM)**, co czyni go idealnym materiałem do nauki budowania nowoczesnych aplikacji webowych w .NET.

### Główne cele projektu:
- Demonstracja różnych trybów renderowania Blazor (Server, WebAssembly, Auto)
- Przykłady integracji z bazą danych (Entity Framework Core + SQLite)
- Implementacja REST API i komunikacji klient-serwer
- Walidacja formularzy po stronie klienta i serwera
- Zarządzanie stanem i nawigacją
- Przykłady Progressive Web App (PWA)

---

## 🏗️ Architektura projektu

Projekt wykorzystuje **architekturę trójwarstwową** z podziałem na:

```
┌─────────────────────────────────────────────────────────┐
│                    Klient (Browser)                      │
│  ┌──────────────────┐         ┌──────────────────┐      │
│  │  Blazor Server   │         │  Blazor WASM     │      │
│  │  (Interactive)   │         │  (Interactive)   │      │
│  └────────┬─────────┘         └────────┬─────────┘      │
└───────────┼────────────────────────────┼────────────────┘
            │                             │
            │         HTTP/HTTPS          │
            ▼                             ▼
┌─────────────────────────────────────────────────────────┐
│              Serwer ASP.NET Core 9.0                     │
│  ┌─────────────────────────────────────────────────┐    │
│  │  Blazor Hosted Server (BlazorExercises)         │    │
│  │  ├─ Razor Components (SSR + Interactive)        │    │
│  │  ├─ REST API Controllers (GamesController)      │    │
│  │  ├─ Services (GameService)                      │    │
│  │  └─ Dependency Injection Container              │    │
│  └──────────────────┬──────────────────────────────┘    │
└────────────────────┼────────────────────────────────────┘
                     │
                     ▼
          ┌──────────────────────┐
          │  Entity Framework    │
          │  Core (GameDbContext)│
          └──────────┬───────────┘
                     │
                     ▼
          ┌──────────────────────┐
          │   SQLite Database    │
          │     (games.db)       │
          └──────────────────────┘
```

### Warstwa prezentacji:
- **BlazorExercises (Server)** - Komponenty Razor z renderowaniem po stronie serwera
- **BlazorExercises.Client (WebAssembly)** - Komponenty uruchamiane w przeglądarce

### Warstwa logiki biznesowej:
- **Services** - Serwisy implementujące logikę aplikacji (`GameService`, `ClientGameService`)
- **Controllers** - REST API endpoints (`GamesController`)

### Warstwa danych:
- **Data** - Konteksty Entity Framework Core (`GameDbContext`)
- **Shared** - Modele danych współdzielone między serwerem a klientem

---

## 🛠️ Technologie i narzędzia

### Technologie podstawowe:
- **.NET 9.0** - Najnowsza wersja platformy .NET
- **ASP.NET Core 9.0** - Framework serwerowy
- **Blazor** - Framework UI do budowania interaktywnych aplikacji webowych
- **C# 12** - Język programowania z najnowszymi funkcjami
- **Razor** - Składnia do tworzenia dynamicznych widoków

### Baza danych:
- **Entity Framework Core 9.0** - ORM (Object-Relational Mapping)
- **SQLite** - Lekka, plikowa baza danych

### Frontend:
- **Blazor Server** - Renderowanie po stronie serwera z SignalR
- **Blazor WebAssembly** - Kod C# uruchamiany w przeglądarce
- **Bootstrap 5** - Framework CSS do stylowania
- **JavaScript Interop** - Integracja z JavaScript

### Narzędzia deweloperskie:
- **Visual Studio 2022** lub **VS Code** - Rekomendowane IDE
- **PowerShell** - Skrypty automatyzacji (start.ps1)
- **dotnet CLI** - Narzędzia wiersza poleceń .NET

### Wzorce i praktyki:
- **Dependency Injection (DI)** - Wzorzec wstrzykiwania zależności
- **Repository Pattern** - Abstrakcja dostępu do danych
- **Data Annotations** - Walidacja modeli
- **REST API** - Architektura API
- **Service Layer Pattern** - Warstwa usług biznesowych

---

## 📦 Struktura rozwiązania

Rozwiązanie składa się z **4 projektów**:

### 1. **BlazorExercises** (Projekt główny - Server)
**Typ:** ASP.NET Core Web App  
**Framework:** .NET 9.0  
**Opis:** Główna aplikacja serwerowa hostująca komponenty Blazor Server, API REST i obsługująca klienta WebAssembly.

**Zawartość:**
- Konfiguracja aplikacji (`Program.cs`)
- Komponenty Razor (strony, layouty)
- Kontrolery API REST
- Serwisy biznesowe
- Kontekst bazy danych
- Middleware i konfiguracja DI

### 2. **BlazorExercises.Client** (WebAssembly Client)
**Typ:** Blazor WebAssembly App  
**Framework:** .NET 9.0  
**Opis:** Aplikacja kliencka uruchamiana w przeglądarce używająca WebAssembly. Komunikuje się z serwerem przez HTTP API.

**Zawartość:**
- Komponenty interaktywne (Counter, EditGame)
- Serwisy klienckie (ClientGameService)
- Konfiguracja HttpClient
- Logika klienta działająca w przeglądarce

### 3. **BlazorExercises.Shared** (Biblioteka współdzielona)
**Typ:** Class Library  
**Framework:** .NET 9.0  
**Opis:** Biblioteka zawierająca wspólne modele danych używane przez serwer i klienta.

**Zawartość:**
- Modele danych (`VideoGame`, `BlogPost`, `ContactForm`)
- Data Annotations do walidacji
- Interfejsy współdzielone

### 4. **BlogSsr** (Dodatkowy projekt demo)
**Typ:** ASP.NET Core Web App  
**Framework:** .NET 9.0  
**Opis:** Osobny, uproszczony projekt demonstracyjny pokazujący czysty Blazor SSR (Server-Side Rendering) bez interaktywności.

**Zawartość:**
- Podstawowe komponenty SSR
- Przykłady statycznego renderowania
- Minimalna konfiguracja

---

## 💻 Wymagania systemowe

### Wymagane:
- **System operacyjny:**
  - Windows 10/11 (64-bit)
  - macOS 12.0 lub nowszy
  - Linux (Ubuntu 20.04+, Debian 11+, Fedora 36+)

- **.NET SDK 9.0 lub nowszy**
  - Pobierz z: https://dotnet.microsoft.com/download/dotnet/9.0
  - Weryfikacja: `dotnet --version` (powinno zwrócić 9.0.x)

- **Przeglądarka internetowa:**
  - Google Chrome 100+ (zalecane)
  - Microsoft Edge 100+
  - Firefox 100+
  - Safari 15+ (macOS)

### Zalecane:
- **IDE:**
  - Visual Studio 2022 (wersja 17.8 lub nowsza) z zainstalowanym workloadem "ASP.NET and web development"
  - Visual Studio Code z rozszerzeniami:
    - C# Dev Kit
    - C# Extensions
    - Blazor WASM Debugger

- **Pamięć RAM:** Minimum 4 GB, zalecane 8 GB+
- **Miejsce na dysku:** ~500 MB na projekt + zależności

---

## 📥 Instalacja i konfiguracja

### Krok 1: Klonowanie lub pobranie projektu

```powershell
# Jeśli używasz Git:
git clone <URL_REPOZYTORIUM>
cd BlazorExercises

# Lub rozpakuj pobrany ZIP do c:\blazer\BlazorExercises
```

### Krok 2: Weryfikacja instalacji .NET SDK

```powershell
dotnet --version
# Wymagana wersja: 9.0.x lub nowsza
```

Jeśli nie masz zainstalowanego .NET 9.0:
1. Odwiedź https://dotnet.microsoft.com/download/dotnet/9.0
2. Pobierz i zainstaluj odpowiednią wersję dla swojego systemu
3. Zrestartuj terminal/PowerShell

### Krok 3: Przywrócenie zależności (NuGet packages)

W katalogu głównym projektu (`c:\blazer\BlazorExercises`):

```powershell
dotnet restore
```

To polecenie pobierze wszystkie wymagane pakiety NuGet:
- Microsoft.EntityFrameworkCore.Sqlite (9.0.10)
- Microsoft.AspNetCore.Components.WebAssembly (9.0.10)
- Microsoft.AspNetCore.Components.WebAssembly.Server (9.0.10)
- System.ComponentModel.Annotations (5.0.0)

### Krok 4: Budowanie projektu

```powershell
dotnet build BlazorExercises.sln
```

Oczekiwany wynik:
```
Build succeeded.
    0 Warning(s)
    0 Error(s)
```

### Krok 5: Inicjalizacja bazy danych

Baza danych SQLite (`games.db`) zostanie automatycznie utworzona przy pierwszym uruchomieniu aplikacji. Kontekst EF Core automatycznie:
- Utworzy plik `games.db` w katalogu `BlazorExercises/`
- Utworzy tabelę `VideoGames`
- Zasili bazę danymi przykładowymi (seed data)

**Seed data (domyślne gry w bazie):**
1. The Legend of Zelda: Breath of the Wild (Nintendo, 2017)
2. The Witcher 3: Wild Hunt (CD Projekt Red, 2015)
3. Elden Ring (FromSoftware, 2022)

---

## 🚀 Uruchomienie aplikacji

### Metoda 1: Użycie skryptu PowerShell (Zalecane)

Najłatwiejszym sposobem uruchomienia projektu jest użycie dołączonego skryptu `start.ps1`:

```powershell
# W katalogu c:\blazer\BlazorExercises
.\start.ps1
```

Skrypt automatycznie:
- ✅ Sprawdzi instalację .NET SDK
- ✅ Zweryfikuje istnienie bazy danych
- ✅ Zbuduje projekt
- ✅ Uruchomi aplikację
- ✅ Wyświetli URL do otwarcia w przeglądarce

### Metoda 2: Ręczne uruchomienie przez dotnet CLI

```powershell
# W katalogu c:\blazer\BlazorExercises
dotnet run --project .\BlazorExercises\BlazorExercises.csproj
```

### Metoda 3: Visual Studio 2022

1. Otwórz `BlazorExercises.sln` w Visual Studio
2. Ustaw `BlazorExercises` jako projekt startowy (prawy przycisk → Set as Startup Project)
3. Naciśnij `F5` (uruchomienie z debuggerem) lub `Ctrl+F5` (bez debuggera)

### Metoda 4: Visual Studio Code

1. Otwórz folder `c:\blazer\BlazorExercises` w VS Code
2. Naciśnij `F5` lub użyj terminalu:
   ```powershell
   dotnet run --project BlazorExercises/BlazorExercises.csproj
   ```

### Dostęp do aplikacji

Po uruchomieniu aplikacja będzie dostępna pod adresami:
- **HTTPS:** https://localhost:5001
- **HTTP:** http://localhost:5000

Otwórz przeglądarkę i przejdź do jednego z powyższych adresów.

**Pierwsze uruchomienie:**
- Może potrwać dłużej (kompilacja, pobieranie WASM)
- Baza danych zostanie automatycznie utworzona
- Certyfikat HTTPS może wymagać zaakceptowania (rozwój lokalny)

---

## 🎨 Funkcjonalności aplikacji

### 1. **Home (Strona główna)**
- **URL:** `/`
- **Opis:** Strona powitalna z opisem projektu
- **Tryb renderowania:** Static SSR
- **Funkcje:** Nawigacja do innych sekcji

### 2. **Counter (Licznik)**
- **URL:** `/counter` (Server) lub `/counter-wasm` (WebAssembly)
- **Opis:** Prosty licznik demonstracyjny
- **Tryby:**
  - `/counter` - Blazor Server (interaktywny, SignalR)
  - `/counter-wasm` - Blazor WebAssembly (uruchamiany w przeglądarce)
- **Funkcje:**
  - Przycisk zwiększający wartość licznika
  - Demonstracja różnic między Server i WASM

### 3. **Weather (Pogoda)**
- **URL:** `/weather`
- **Opis:** Przykładowa tabela z danymi pogodowymi
- **Tryb:** SSR z Stream Rendering
- **Funkcje:**
  - Generowanie losowych danych
  - Opóźnione ładowanie (streaming)
  - Responsywna tabela Bootstrap

### 4. **Blog**
- **URL:** `/blog`
- **Opis:** Lista postów blogowych
- **Tryb:** SSR z Stream Rendering
- **Funkcje:**
  - Wyświetlanie postów w kartach (cards)
  - Informacje o autorze i dacie publikacji
  - Symulacja opóźnienia ładowania

### 5. **Contact (Kontakt)**
- **URL:** `/contact`
- **Opis:** Formularz kontaktowy (dwie wersje)
- **Funkcje:**
  - **Wersja 1:** Static SSR (POST bez JavaScript)
  - **Wersja 2:** Interactive Server (z walidacją)
  - Walidacja po stronie klienta i serwera
  - Data Annotations (Required, Email, StringLength)
  - Wyświetlanie błędów walidacji

### 6. **Games (Lista gier)**
- **URL:** `/games`
- **Opis:** Lista gier wideo z bazy danych
- **Tryb:** Interactive Server
- **Funkcje:**
  - Wyświetlanie wszystkich gier z bazy
  - Przycisk dodawania nowej gry
  - Przyciski edycji i usuwania dla każdej gry
  - Refresh listy po zmianach
  - Komunikaty o sukcesie/błędzie

### 7. **Edit Game (Edycja gry)**
- **URL:** `/edit-game` (nowa) lub `/edit-game/{id}` (edycja)
- **Opis:** Formularz dodawania/edycji gry
- **Dostępne w dwóch wersjach:**
  - **Server:** `/edit-game/{id}` (w folderze Components/Pages)
  - **WASM:** `/edit-game` (w folderze Client/Pages)
- **Funkcje:**
  - Walidacja formularza (DataAnnotations)
  - Komunikacja z API REST
  - Obsługa stanów: ładowanie, zapisywanie, błędy
  - Nawigacja powrotna po zapisie
  - Wyświetlanie błędów walidacji w czasie rzeczywistym

### 8. **PWA Info**
- **URL:** `/pwa-info`
- **Opis:** Informacje o Progressive Web App
- **Funkcje:**
  - Instrukcje instalacji PWA
  - Informacje o Service Worker
  - Status offline/online

---

## 🔍 Szczegółowy opis komponentów

### Program.cs (BlazorExercises)

Główny plik konfiguracyjny aplikacji:

```csharp
// Rejestracja komponentów Razor z obsługą różnych trybów
builder.Services.AddRazorComponents()
    .AddInteractiveServerComponents()      // Blazor Server
    .AddInteractiveWebAssemblyComponents(); // Blazor WASM

// Konfiguracja bazy danych SQLite
builder.Services.AddDbContext<GameDbContext>(options =>
    options.UseSqlite("Data Source=games.db"));

// Rejestracja serwisów
builder.Services.AddScoped<IGameService, GameService>();

// Dodanie obsługi kontrolerów API
builder.Services.AddControllers();
```

**Kluczowe elementy:**
- **Dependency Injection (DI):** Wszystkie serwisy rejestrowane w kontenerze DI
- **Scoped Services:** `GameService` ma lifetime "scoped" (jedna instancja per request)
- **Entity Framework:** Automatyczna inicjalizacja bazy (`EnsureCreated()`)
- **Routing:** Mapowanie komponentów i kontrolerów API

---

### GamesController.cs (REST API)

Kontroler API obsługujący operacje CRUD na grach:

**Endpoints:**

| Metoda | URL | Opis | Request Body | Response |
|--------|-----|------|--------------|----------|
| GET | `/api/games` | Pobierz wszystkie gry | - | `List<VideoGame>` |
| GET | `/api/games/{id}` | Pobierz grę po ID | - | `VideoGame` lub 404 |
| POST | `/api/games` | Dodaj nową grę | `VideoGame` | `VideoGame` (201 Created) |
| PUT | `/api/games/{id}` | Zaktualizuj grę | `VideoGame` | `VideoGame` lub 404 |
| DELETE | `/api/games/{id}` | Usuń grę | - | 204 No Content lub 404 |

**Przykład użycia (cURL):**

```bash
# Pobierz wszystkie gry
curl https://localhost:5001/api/games

# Dodaj nową grę
curl -X POST https://localhost:5001/api/games \
  -H "Content-Type: application/json" \
  -d '{"title":"Cyberpunk 2077","publisher":"CD Projekt Red","releaseYear":2020}'
```

**Obsługa błędów:**
- 400 Bad Request - Nieprawidłowa walidacja modelu
- 404 Not Found - Gra nie istnieje
- 201 Created - Gra została dodana (zwraca URL w nagłówku Location)

---

### GameService.cs (Logika biznesowa)

Serwis implementujący operacje na bazie danych:

**Metody:**
- `GetAllGamesAsync()` - Pobiera wszystkie gry
- `GetGameByIdAsync(int id)` - Pobiera grę po ID
- `AddGameAsync(VideoGame game)` - Dodaje nową grę
- `UpdateGameAsync(VideoGame game)` - Aktualizuje istniejącą grę
- `DeleteGameAsync(int id)` - Usuwa grę

**Wzorzec:**
- Implementacja interfejsu `IGameService`
- Asynchroniczne operacje (async/await)
- Obsługa DbContext przez DI

---

### ClientGameService.cs (Klient WebAssembly)

Serwis kliencki komunikujący się z API przez HTTP:

```csharp
public async Task<List<VideoGame>> GetAllGamesAsync()
{
    return await _httpClient.GetFromJsonAsync<List<VideoGame>>("api/games") 
           ?? new List<VideoGame>();
}
```

**Różnica między GameService a ClientGameService:**
- **GameService:** Bezpośredni dostęp do bazy danych (serwer)
- **ClientGameService:** Wywołania HTTP do API REST (klient WASM)
- Oba implementują ten sam interfejs `IGameService`

---

### GameDbContext.cs (Warstwa danych)

Entity Framework Core DbContext:

```csharp
public class GameDbContext : DbContext
{
    public DbSet<VideoGame> VideoGames { get; set; }
    
    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        // Seed data - dane inicjalne
        modelBuilder.Entity<VideoGame>().HasData(
            new VideoGame { Id = 1, Title = "...", ... }
        );
    }
}
```

**Funkcje:**
- Definicja tabel (DbSet)
- Seed data (dane przykładowe)
- Konfiguracja relacji (jeśli istnieją)

---

### Modele danych (Shared)

#### VideoGame.cs

```csharp
public class VideoGame
{
    public int Id { get; set; }
    
    [Required(ErrorMessage = "Tytuł jest wymagany")]
    [StringLength(100, ErrorMessage = "Tytuł nie może być dłuższy niż 100 znaków")]
    public string Title { get; set; }
    
    [Required(ErrorMessage = "Wydawca jest wymagany")]
    public string Publisher { get; set; }
    
    [Required(ErrorMessage = "Rok wydania jest wymagany")]
    [Range(1970, 2100, ErrorMessage = "Rok wydania musi być między 1970 a 2100")]
    public int ReleaseYear { get; set; }
}
```

**Data Annotations:**
- `[Required]` - Pole wymagane
- `[StringLength]` - Ograniczenie długości tekstu
- `[Range]` - Zakres wartości liczbowych
- `[EmailAddress]` - Walidacja formatu email (w ContactForm)

---

## 🗄️ Baza danych

### Konfiguracja

**Connection String:**
```json
{
  "ConnectionStrings": {
    "DefaultConnection": "Data Source=games.db"
  }
}
```

**Lokalizacja pliku:** `BlazorExercises/games.db`

### Schemat bazy danych

**Tabela: VideoGames**

| Kolumna | Typ | Ograniczenia | Opis |
|---------|-----|--------------|------|
| Id | INTEGER | PRIMARY KEY, AUTOINCREMENT | Unikalny identyfikator |
| Title | TEXT | NOT NULL, MaxLength(100) | Tytuł gry |
| Publisher | TEXT | NOT NULL, MaxLength(100) | Wydawca |
| ReleaseYear | INTEGER | NOT NULL, Range(1970-2100) | Rok wydania |

### Zarządzanie bazą danych

**Inicjalizacja (automatyczna):**
```csharp
// W Program.cs
using (var scope = app.Services.CreateScope())
{
    var context = scope.ServiceProvider.GetRequiredService<GameDbContext>();
    context.Database.EnsureCreated(); // Tworzy bazę + seed data
}
```

**Przeglądanie bazy danych:**

Możesz użyć różnych narzędzi do przeglądania SQLite:
- **DB Browser for SQLite** (https://sqlitebrowser.org/)
- **Visual Studio Code** z rozszerzeniem "SQLite"
- **DataGrip** (JetBrains)
- **Azure Data Studio**

**Resetowanie bazy danych:**

Jeśli chcesz zresetować bazę do stanu początkowego:
```powershell
# Usuń plik bazy danych
Remove-Item .\BlazorExercises\games.db

# Uruchom aplikację ponownie - baza zostanie odtworzona
dotnet run --project .\BlazorExercises\BlazorExercises.csproj
```

---

## 🌐 API REST

### Base URL

```
https://localhost:5001/api
```

### Dokumentacja endpointów

#### GET /api/games
Pobiera listę wszystkich gier.

**Response 200 OK:**
```json
[
  {
    "id": 1,
    "title": "The Legend of Zelda: Breath of the Wild",
    "publisher": "Nintendo",
    "releaseYear": 2017
  },
  ...
]
```

---

#### GET /api/games/{id}
Pobiera szczegóły pojedynczej gry.

**Parametry:**
- `id` (int) - ID gry

**Response 200 OK:**
```json
{
  "id": 1,
  "title": "The Legend of Zelda: Breath of the Wild",
  "publisher": "Nintendo",
  "releaseYear": 2017
}
```

**Response 404 Not Found:**
```json
{
  "type": "https://tools.ietf.org/html/rfc7231#section-6.5.4",
  "title": "Not Found",
  "status": 404
}
```

---

#### POST /api/games
Dodaje nową grę.

**Request Body:**
```json
{
  "title": "Cyberpunk 2077",
  "publisher": "CD Projekt Red",
  "releaseYear": 2020
}
```

**Response 201 Created:**
```json
{
  "id": 4,
  "title": "Cyberpunk 2077",
  "publisher": "CD Projekt Red",
  "releaseYear": 2020
}
```

**Headers:**
```
Location: /api/games/4
```

**Response 400 Bad Request (błąd walidacji):**
```json
{
  "type": "https://tools.ietf.org/html/rfc7231#section-6.5.1",
  "title": "One or more validation errors occurred.",
  "status": 400,
  "errors": {
    "Title": ["Tytuł jest wymagany"]
  }
}
```

---

#### PUT /api/games/{id}
Aktualizuje istniejącą grę.

**Parametry:**
- `id` (int) - ID gry do zaktualizowania

**Request Body:**
```json
{
  "id": 1,
  "title": "The Legend of Zelda: BOTW",
  "publisher": "Nintendo",
  "releaseYear": 2017
}
```

**Response 200 OK:**
```json
{
  "id": 1,
  "title": "The Legend of Zelda: BOTW",
  "publisher": "Nintendo",
  "releaseYear": 2017
}
```

**Response 400 Bad Request:**
ID w URL nie zgadza się z ID w body.

**Response 404 Not Found:**
Gra o podanym ID nie istnieje.

---

#### DELETE /api/games/{id}
Usuwa grę.

**Parametry:**
- `id` (int) - ID gry do usunięcia

**Response 204 No Content:**
Gra została usunięta (brak zawartości w odpowiedzi).

**Response 404 Not Found:**
Gra o podanym ID nie istnieje.

---

### Testowanie API

**Przy użyciu PowerShell:**
```powershell
# GET - Pobierz wszystkie gry
Invoke-RestMethod -Uri "https://localhost:5001/api/games" -Method GET

# POST - Dodaj nową grę
$body = @{
    title = "Hogwarts Legacy"
    publisher = "Warner Bros"
    releaseYear = 2023
} | ConvertTo-Json

Invoke-RestMethod -Uri "https://localhost:5001/api/games" `
    -Method POST `
    -Body $body `
    -ContentType "application/json"
```

**Przy użyciu Postman:**
1. Otwórz Postman
2. Utwórz nowy request
3. Ustaw URL: `https://localhost:5001/api/games`
4. Wybierz metodę (GET, POST, PUT, DELETE)
5. W zakładce "Body" wybierz "raw" i "JSON"
6. Wyślij request

---

## ⚡ Tryby renderowania Blazor

Projekt demonstruje **3 różne tryby renderowania** Blazor:

### 1. Static Server-Side Rendering (Static SSR)

**Charakterystyka:**
- Renderowanie tylko po stronie serwera
- Brak interaktywności (JavaScript)
- Szybkie pierwsze ładowanie (FCP)
- SEO-friendly

**Przykład:**
```razor
@page "/blog"
@attribute [StreamRendering(true)]

<h1>Blog</h1>
@foreach (var post in posts)
{
    <div>@post.Title</div>
}
```

**Użycie:** Strony statyczne, blogi, landing pages

---

### 2. Interactive Server (Blazor Server)

**Charakterystyka:**
- Interaktywność przez połączenie SignalR
- Stan aplikacji na serwerze
- Szybka reakcja (niski overhead)
- Wymaga stałego połączenia

**Przykład:**
```razor
@page "/counter"
@rendermode InteractiveServer

<button @onclick="IncrementCount">Click me</button>
<p>Count: @currentCount</p>

@code {
    private int currentCount = 0;
    
    private void IncrementCount()
    {
        currentCount++;
    }
}
```

**Użycie:** Dashboardy, formularze, aplikacje real-time

---

### 3. Interactive WebAssembly (Blazor WASM)

**Charakterystyka:**
- Kod C# uruchamiany w przeglądarce
- Brak zależności od serwera (po załadowaniu)
- Większy rozmiar początkowego ładowania
- Działa offline (z PWA)

**Przykład:**
```razor
@page "/counter-wasm"
@rendermode InteractiveWebAssembly

<button @onclick="IncrementCount">Click me</button>
<p>Count: @currentCount</p>

@code {
    private int currentCount = 0;
    
    private void IncrementCount()
    {
        currentCount++;
    }
}
```

**Użycie:** SPA, aplikacje offline, PWA

---

### Porównanie trybów

| Cecha | Static SSR | Interactive Server | Interactive WASM |
|-------|------------|-------------------|------------------|
| Interaktywność | ❌ Nie | ✅ Tak (SignalR) | ✅ Tak (local) |
| Pierwsze ładowanie | ⚡ Bardzo szybkie | ⚡ Szybkie | 🐌 Wolniejsze |
| Wymagania sieciowe | 📶 Tylko HTTP | 📶 Stałe połączenie | 📶 Tylko API calls |
| SEO | ✅ Doskonałe | ⚠️ Dobre | ❌ Ograniczone |
| Skalowalność | ⬆️ Bardzo dobra | ⬆️ Średnia | ⬆️ Doskonała |
| Offline | ❌ Nie | ❌ Nie | ✅ Tak (z PWA) |

---

## 🛠️ Rozwój i debugowanie

### Uruchomienie w trybie deweloperskim

```powershell
# Z hot reload (automatyczne przeładowanie)
dotnet watch --project .\BlazorExercises\BlazorExercises.csproj
```

Po zapisaniu zmian w plikach `.razor`, `.cs` lub `.cshtml` aplikacja automatycznie się przebuduje i odświeży.

### Debugowanie w Visual Studio

1. Ustaw breakpoint w kodzie (kliknij na marginesie linii)
2. Naciśnij `F5` aby uruchomić z debuggerem
3. Wykonaj akcję w aplikacji która wywoła kod
4. Debugger zatrzyma się na breakpoincie
5. Używaj `F10` (Step Over), `F11` (Step Into), `F5` (Continue)

### Debugowanie Blazor WebAssembly

**W przeglądarce Chrome/Edge:**
1. Uruchom aplikację
2. Przejdź do strony WASM (np. `/counter-wasm`)
3. Naciśnij `Shift + Alt + D`
4. Postępuj zgodnie z instrukcjami (uruchom przeglądarkę w trybie debugowania)
5. Ustaw breakpointy w DevTools (Sources → `file://` → Twój kod)

### Logi i diagnostyka

**Dodaj logi w kodzie:**
```csharp
@inject ILogger<EditGame> Logger

@code {
    protected override void OnInitialized()
    {
        Logger.LogInformation("Komponent EditGame został zainicjalizowany");
    }
}
```

**Przeglądaj logi w konsoli:**
- Visual Studio: Output → Debug
- VS Code: Terminal
- Przeglądarka: F12 → Console

### Czyszczenie projektu

Jeśli masz problemy z buildem:

```powershell
# Wyczyść artefakty
dotnet clean

# Usuń foldery bin i obj
Get-ChildItem -Path . -Include bin,obj -Recurse | Remove-Item -Recurse -Force

# Przywróć pakiety
dotnet restore

# Zbuduj ponownie
dotnet build
```

---

## 📁 Struktura folderów

### BlazorExercises (Server)

```
BlazorExercises/
├── Components/                  # Komponenty Razor
│   ├── Layout/                  # Layouty (MainLayout, NavMenu)
│   │   ├── MainLayout.razor     # Główny layout aplikacji
│   │   ├── MainLayout.razor.css # Style dla layoutu
│   │   ├── NavMenu.razor        # Menu nawigacyjne
│   │   └── NavMenu.razor.css    # Style dla menu
│   ├── Pages/                   # Strony aplikacji
│   │   ├── Home.razor           # Strona główna
│   │   ├── Blog.razor           # Blog (SSR + Streaming)
│   │   ├── Contact.razor        # Formularz kontaktowy (2 wersje)
│   │   ├── Games.razor          # Lista gier (Interactive Server)
│   │   ├── EditGame.razor       # Edycja gry (Server)
│   │   ├── Weather.razor        # Pogoda (SSR)
│   │   ├── CounterServer.razor  # Licznik (Server)
│   │   ├── PwaInfo.razor        # Informacje o PWA
│   │   └── Error.razor          # Strona błędu
│   ├── App.razor                # Główny komponent aplikacji
│   ├── Routes.razor             # Konfiguracja routingu
│   └── _Imports.razor           # Globalne using statements
├── Controllers/                 # Kontrolery API REST
│   └── GamesController.cs       # CRUD API dla gier
├── Data/                        # Warstwa danych
│   └── GameDbContext.cs         # Entity Framework DbContext
├── Services/                    # Serwisy biznesowe
│   ├── IGameService.cs          # Interfejs serwisu gier
│   └── GameService.cs           # Implementacja serwisu (serwer)
├── wwwroot/                     # Pliki statyczne
│   ├── app.css                  # Główne style CSS
│   ├── manifest.json            # Manifest PWA
│   ├── service-worker.js        # Service Worker (PWA)
│   ├── service-worker-register.js # Rejestracja SW
│   └── lib/                     # Biblioteki (Bootstrap, etc.)
├── Properties/
│   └── launchSettings.json      # Konfiguracja uruchamiania
├── Program.cs                   # Punkt wejścia aplikacji
├── appsettings.json             # Konfiguracja aplikacji
├── appsettings.Development.json # Konfiguracja dev
├── BlazorExercises.csproj       # Plik projektu
└── games.db                     # Baza danych SQLite (generowana)
```

### BlazorExercises.Client (WebAssembly)

```
BlazorExercises.Client/
├── Pages/                       # Strony WASM
│   ├── Counter.razor            # Licznik (WASM, auto)
│   ├── CounterWasm.razor        # Licznik (tylko WASM)
│   └── EditGame.razor           # Edycja gry (WASM)
├── Services/                    # Serwisy klienckie
│   ├── IGameService.cs          # Interfejs (współdzielony)
│   └── ClientGameService.cs     # Implementacja HTTP (klient)
├── wwwroot/                     # Pliki statyczne WASM
│   ├── appsettings.json         # Konfiguracja klienta
│   └── appsettings.Development.json
├── Program.cs                   # Punkt wejścia WASM
├── _Imports.razor               # Globalne using
└── BlazorExercises.Client.csproj # Plik projektu WASM
```

### BlazorExercises.Shared (Biblioteka)

```
BlazorExercises.Shared/
├── VideoGame.cs                 # Model gry wideo
├── BlogPost.cs                  # Model posta blogowego
├── ContactForm.cs               # Model formularza kontaktowego
├── Class1.cs                    # Przykładowa klasa
└── BlazorExercises.Shared.csproj # Plik projektu
```

### BlogSsr (Projekt demo)

```
BlogSsr/
├── Components/                  # Komponenty czystego SSR
│   ├── Layout/
│   │   ├── MainLayout.razor
│   │   └── NavMenu.razor
│   ├── Pages/
│   │   ├── Home.razor
│   │   ├── Weather.razor
│   │   └── Error.razor
│   ├── App.razor
│   └── Routes.razor
├── wwwroot/                     # Statyczne pliki
│   ├── app.css
│   └── lib/
├── Program.cs                   # Minimalna konfiguracja SSR
├── appsettings.json
└── BlogSsr.csproj
```

---

## ❓ Najczęstsze problemy

### Problem: "Nie można znaleźć .NET SDK"

**Objawy:**
```
The command 'dotnet' could not be found
```

**Rozwiązanie:**
1. Zainstaluj .NET 9.0 SDK z https://dotnet.microsoft.com/download
2. Zrestartuj terminal/PowerShell
3. Sprawdź: `dotnet --version`

---

### Problem: "Port 5001 jest już używany"

**Objawy:**
```
Failed to bind to address https://127.0.0.1:5001: address already in use.
```

**Rozwiązanie 1 - Zmiana portu:**
Edytuj `Properties/launchSettings.json`:
```json
{
  "applicationUrl": "https://localhost:5501;http://localhost:5500"
}
```

**Rozwiązanie 2 - Zakończ proces na porcie:**
```powershell
# Znajdź proces używający portu 5001
netstat -ano | findstr :5001

# Zakończ proces (PID z poprzedniego polecenia)
taskkill /PID <PID> /F
```

---

### Problem: "Cannot find 'games.db'"

**Objawy:**
```
SQLite Error: unable to open database file
```

**Rozwiązanie:**
1. Sprawdź ścieżkę w `appsettings.json`
2. Upewnij się, że masz uprawnienia zapisu w katalogu projektu
3. Uruchom aplikację jako administrator (Windows) lub z odpowiednimi uprawnieniami

---

### Problem: "Błędy kompilacji TypeScript/CSS"

**Objawy:**
Błędy podczas budowania związane z assets.

**Rozwiązanie:**
```powershell
# Wyczyść cache
dotnet clean

# Usuń node_modules (jeśli istnieje)
Remove-Item -Recurse -Force node_modules

# Zbuduj ponownie
dotnet build
```

---

### Problem: "Blazor WASM nie działa"

**Objawy:**
Strony WASM nie ładują się, błąd 404 dla plików .dll.

**Rozwiązanie:**
1. Sprawdź czy projekt `BlazorExercises.Client` jest zbudowany
2. Sprawdź czy w `Program.cs` jest: `app.UseWebAssemblyDebugging();`
3. Wyczyść cache przeglądarki (Ctrl+Shift+Delete)
4. Sprawdź konsolę przeglądarki (F12) pod kątem błędów

---

### Problem: "Certyfikat HTTPS nie jest zaufany"

**Objawy:**
Przeglądarka pokazuje ostrzeżenie o certyfikkacie.

**Rozwiązanie:**
```powershell
# Zaufaj certyfikatowi deweloperskiego HTTPS
dotnet dev-certs https --trust
```

Potwierdź w oknie dialogowym systemu.

---

### Problem: "Hot Reload nie działa"

**Objawy:**
Zmiany w kodzie nie są widoczne bez restartu.

**Rozwiązanie:**
1. Upewnij się, że używasz `dotnet watch`:
   ```powershell
   dotnet watch --project .\BlazorExercises\BlazorExercises.csproj
   ```
2. Sprawdź czy plik ma status "Saved" (zapisany)
3. Niektóre zmiany wymagają pełnego restartu (np. zmiany w `Program.cs`)

---

### Problem: "Entity Framework nie tworzy bazy danych"

**Objawy:**
Brak pliku `games.db`, błędy SQL.

**Rozwiązanie:**
1. Sprawdź connection string w `appsettings.json`
2. Upewnij się, że w `Program.cs` jest wywołanie `EnsureCreated()`:
   ```csharp
   using (var scope = app.Services.CreateScope())
   {
       var context = scope.ServiceProvider.GetRequiredService<GameDbContext>();
       context.Database.EnsureCreated();
   }
   ```
3. Sprawdź logi w konsoli

---

## 📚 Dodatkowe zasoby

### Dokumentacja oficjalna:
- **ASP.NET Core:** https://docs.microsoft.com/aspnet/core
- **Blazor:** https://docs.microsoft.com/aspnet/core/blazor
- **Entity Framework Core:** https://docs.microsoft.com/ef/core
- **.NET 9.0:** https://docs.microsoft.com/dotnet/core/whats-new/dotnet-9

### Tutoriale:
- **Microsoft Learn - Blazor:** https://learn.microsoft.com/training/paths/build-web-apps-with-blazor/
- **Blazor University:** https://blazor-university.com/
- **Awesome Blazor:** https://github.com/AdrienTorris/awesome-blazor

### Community:
- **Blazor Discord:** https://aka.ms/blazor-discord
- **Stack Overflow:** Tag `blazor`
- **Reddit:** r/Blazor

---

## 📝 Notatki dla deweloperów

### Dodawanie nowej strony

1. Utwórz nowy plik `.razor` w `Components/Pages/`
2. Dodaj dyrektywę `@page "/url"`
3. Opcjonalnie dodaj link w `NavMenu.razor`

**Przykład:**
```razor
@page "/my-new-page"

<PageTitle>Moja nowa strona</PageTitle>

<h1>Witaj na nowej stronie!</h1>

@code {
    // Logika strony
}
```

### Dodawanie nowego modelu do bazy danych

1. Utwórz klasę modelu w `Shared/`
2. Dodaj `DbSet` w `GameDbContext.cs`:
   ```csharp
   public DbSet<MyModel> MyModels { get; set; }
   ```
3. Usuń bazę danych (`games.db`)
4. Uruchom aplikację (baza zostanie odtworzona)

### Tworzenie nowego API endpoint

1. Utwórz kontroler w `Controllers/`:
   ```csharp
   [ApiController]
   [Route("api/[controller]")]
   public class MyController : ControllerBase
   {
       [HttpGet]
       public ActionResult<List<MyModel>> GetAll()
       {
           // ...
       }
   }
   ```
2. API będzie dostępne pod `/api/my`

---

## 📄 Licencja

Ten projekt jest udostępniony jako materiał edukacyjny. Możesz go wykorzystać do nauki, modyfikować i rozwijać według własnych potrzeb.

---

## 🤝 Wkład w projekt

Jeśli chcesz wnieść swój wkład w rozwój tego projektu:
1. Fork repozytorium
2. Utwórz branch z funkcją (`git checkout -b feature/AmazingFeature`)
3. Commit zmian (`git commit -m 'Add some AmazingFeature'`)
4. Push do brancha (`git push origin feature/AmazingFeature`)
5. Otwórz Pull Request

---

## ✉️ Kontakt

W razie pytań lub problemów, otwórz Issue w repozytorium GitHub.

---

**Powodzenia w nauce Blazor! 🚀**

*Data aktualizacji: Listopad 2025*
*Wersja dokumentacji: 1.0*
